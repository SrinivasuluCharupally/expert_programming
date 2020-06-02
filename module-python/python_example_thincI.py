import getopt,sys,os
import errno
import pwd
import re,commands

CRED = '\033[91m'
CEND = '\033[0m'
CGREEN='\33[32m'

err_count=0

def pr(inp):
    print(CRED + inp +CEND)

def pg(inp):
    print(CGREEN + inp +CEND)
    
def ocommands(cmd):
    pr('Executing %s' % cmd )
    try:
        out=commands.getstatusoutput(cmd)
        if out[0]==0 or out[0]==256:
            print out[1]
            if re.search('.*abort: out of memory.*|.*rollback.*', out[1]):
                pr('Unable to execute command=%s\n Resubmitting the command' % cmd)
                if err_count<=3:
                    err_count=err_count+1
                    ocommands(cmd)
                else:
                    pr('Issue with the command=%s' %cmd)
                    sys.exit(2)
            elif re.search('.*make error.*|.*[f,F]ailure.*|.*fatal error:.*|.*Makefile:.*:.*recipe for target.* failed.*',out[1]):
                pr("Issue with Package Installation")
                sys.exit(2)
        else:
            pr("Issue in System call=%s\nError message=%s" % (cmd,out[1]))
            sys.exit(2)
    except Exception as e:
        pr("Issue in System call=%s and error=%s\nError message=%s" % (cmd,out[1],e))
        sys.exit(2)
        
def ochdir(cmd):
    pr('Executing %s' % cmd )
    try:
        p2=os.chdir(cmd)
        pr(os.getcwd())
    except Exception as e:
        pr("Issue in changing directory to %s,error=%s\nError message=%s" % (cmd,p2,e))
        sys.exit(2)
        
def usage(cmd):
    print(CGREEN + cmd )
    pr('The script takes two mandatory arguments -u(username),-o(option) and a optional argument -d(sdk directory name) which is optional')
    pr('Here -u takes the username of system user other than root. Please make sure that the user exists on the system')
    pr('Here -o takes two values(1 or 2) It should be 1 if you are executing the script for the first time')
    pr("Here -d takes the sdk directory name. If you don't specify -d option it assumes sdk_release_build as sdk name")
    sys.exit(2)
    
def ojoin(input1,input2):
    pr("Joining %s,%s" % (input1,input2) )
    try:
        return os.path.join(input1,input2)
    except Exception as e:
        pr("Unable to join paths %s, %s\nError message=%s" % (input1,input2,e))
        sys.exit(2)
        
def get_arg(self):
    pr("Reading command line arguments")
    if(len(sys.argv)<5 or len(sys.argv)>7):
        usage(self.cmd)
    try:
        opts, args = getopt.getopt(sys.argv[1:],"hu:o:d:",["user=","option=","dir_name="])
    except getopt.GetoptError:
        usage(self.cmd)
    for opt, arg in opts:
        if opt == '-h':
            print self.cmd
            sys.exit(2)
        elif opt in ("-u", "--user"):
            self.user = arg
        elif opt in ("-o", "--option"):
            self.option = int(arg)
        elif opt in ("-d", "--dir_name"):
            self.sdk_name = arg
        else:
            usage(self.cmd)
    if self.user=='' or self.sdk_name=='' or self.option==-1:
        usage(self.cmd)
    try:
        p1=pwd.getpwnam(self.user)
    except KeyError:
        pr('User "%s" does not exist. Please enter a valid username' % self.user)
        usage(self.cmd)
    self.sdk_path=ojoin(p1.pw_dir,'Documents/%s' % (self.sdk_name))
    if os.path.isdir(self.sdk_path)==True and self.option==1:
        pr('A directory with name="%s" already exists in %s' % (self.sdk_name,self.sdk_path))
        usage(self.cmd)
    if os.path.isdir(self.sdk_path)==False and self.option==2:
        pr('%s should exists when -o is 2' % self.sdk_path)
        usage(self.cmd)        
def exe_cmds(self):
    for cmd in self.cmds: 
        ocommands(cmd)

def sdk_dir(self):
    pr("Creating sdk directory")
    cmd='/home/%s/Documents/%s' % (self.user,self.sdk_name)
    ocommands('mkdir -p %s' % cmd)
        
def clone_repo(self):
    pr("Cloning repo in %s direcotry" % self.sdk_path)
    try:
        ochdir('%s' % self.sdk_path)
        ocommands('apt install -y mercurial')
        ocommands(self.dir['tcsim'])
        ocommands(self.dir['swtests'])
        ocommands(self.dir['driver'])
        ocommands(self.dir['openvx'])
        ocommands(self.dir['compiler'])
        ocommands(self.dir['opensrc'])
    except Exception as e:
        pr('Unable to clone repository\nError message=%s' % e )

def check_repo(self):
    ochdir(self.sdk_path)
    if os.path.isdir('v1')==True and os.path.isdir('swtests')==True and os.path.isdir('driver')==True and os.path.isdir('openvx')==True and os.path.isdir('compiler')==True and os.path.isdir('opensrc')==True:
        pr("All the repositories are cloned successfully" )
    else:
        pr("All the repositories are not cloned successfully" )
        sys.exit(2)
    
def crt_soft_link(self):
    pr("Creating Softlink in v1 folder")
    try:
        ochdir('%s' % ojoin(self.sdk_path,'v1'))
        ocommands('ln -s ../driver ./driver')
    except OSError as e:
        if e.errno == errno.EEXIST:
            pr('Directory not created.')
        else:
            raise
def crt_prefix_dir(self):
    pr("Creating Prefix Directory")
    cmd='/home/%s/Documents/%s/PREFIX_DIR' % (self.user,self.sdk_name)
    ocommands('mkdir -p %s' % cmd)

def export_env(self):
    pr("Exporting Environment Variables")
    try:
        pr("Exporting Environment Variables to bashrc") 
        path=ojoin('/home/%s' % self.user,'.bashrc')
        pr('%s' % path ) 
        with open(path,'a') as f:
            f.write('export PROJECT_DIR=/home/%s/Documents/%s\n' % (self.user,self.sdk_name))
            f.write('export PREFIX_DIR=$PROJECT_DIR/PREFIX_DIR\n')
            f.write('export LD_LIBRARY_PATH=$PREFIX_DIR/lib/soft:$PREFIX_DIR/lib/\n')
            f.write('export LITMUS_BASE_PATH=/home/%s/Documents/%s/swtests/cv/litmus\n' % (self.user,self.sdk_name))
            f.write('export VXDRIVER_BASE_PATH=$PROJECT_DIR/openvx/v1.0/driver\n')
        print(CGREEN +"Execute the following commands in the same order after this script ends"+CEND)
        print(CGREEN +"source %s" % path+CEND)
        cmd='python %s -u %s -o 2 -d %s' % (sys.argv[0].split('/')[-1],self.user,self.sdk_name)
        print(CGREEN +"%s" % cmd+CEND)
    except Exception as e:
        pr('Unable to open %s file for appending\nError message=%s' % (path,e))

def make_cmd(cmd):
    pr('%s' % cmd )
    ochdir(cmd)
    ocommands('sh config_target.sh')
    ocommands('make clean')
    ocommands('make')
    ocommands('make install')
    
def make_cmds():
    ocommands('make')
    ocommands('make install')

def build_clang(self):
    pr("Building Clang")
    try:
        make_cmd(ojoin(self.sdk_path,'v1/tcsim'))
        make_cmd(ojoin(self.sdk_path,'v1/driver/libdrm'))
        ochdir(ojoin(self.sdk_path,'compiler'))
        ocommands('sh config_target.sh')
        ochdir(ojoin(self.sdk_path,'compiler/5.0'))
        ocommands('make distclean')
        ocommands('make clang')
        make_cmds()
        ochdir(ojoin(self.sdk_path,'compiler/libCL2'))
        make_cmds()
        ochdir(ojoin(self.sdk_path,'openvx/v1.0/driver'))
        ocommands('sh config_target.sh')
        make_cmds()
        ochdir(ojoin(self.sdk_path,'openvx/v1.0/std'))
        ocommands('./compile.sh')
        ochdir(ojoin(self.sdk_path,'swtests/cv/litmus'))
        ocommands('make')
        ochdir(ojoin(self.sdk_path,'hasm/dev2'))
        ocommands('make clean')
        ocommands('make lib')
        ocommands('make install')
        ocommands('make')
        ochdir(ojoin(self.sdk_path,'dnn_fmwk/devx/std'))
        ocommands('make clean')
        ocommands('make lib')
        ocommands('make install')
        ochdir(ojoin(self.sdk_path,'dnn_fmwk/devx/thinci'))
        ocommands('make clean')
        ocommands('make lib')
        ocommands('make install')
        ochdir(ojoin(self.sdk_path,'blas/dev/thinci'))
        ocommands('make clean')
        ocommands('make lib')
        ocommands('make install')
        pg("SDK INSTALLED SUCCESSFULLY")
    except Exception as e:
        pr('Error while building clang\nError message=%s' % e )

def install_hipchat(self):
    pr("Installing Hipchat")
    ocommands('echo "deb http://downloads.hipchat.com/linux/apt stable main" > /etc/apt/sources.list.d/atlassian-hipchat.list')
    ocommands('wget -O - https://www.hipchat.com/keys/hipchat-linux.key | apt-key add -')
    ocommands('apt-get update')
    ocommands('apt-get --allow-unauthenticated -y install hipchat')
    ocommands('apt-get -y -f install')
    ocommands('apt-get --allow-unauthenticated -y install hipchat')
    pg('Hipchat installed sucessfully')
class install_tci_sdk:
    def __init__(self):
        self.user=''
        self.sdk_name='sdk_release_build'
        self.cmds=['apt-get -y install libpthread-stubs0-dev', 'apt-get -y install libpciaccess-dev', 'apt-get -y install autoconf', 'apt-get -y install libtool', 'apt-get -y install xutils-dev', 'apt-get -y install libx11-dev', 'apt-get -y install g++-5', 'ln -sf /usr/bin/g++-5 /usr/bin/g++', 'apt-get -y install byacc', 'apt-get -y install g++-multilib','apt-get -y install bison', 'apt-get -y install flex', 'apt-get -y install zlib1g-dev', 'apt-get -y install libxml2-dev', 'apt-get -y install dpkg-dev', 'apt-get -y install cmake', 'apt-get -y install vim', 'apt-get -y install build-essential subversion swig python2.7-dev', 'apt-get -y install libedit-dev libncurses5-dev', 'apt-get -y install doxygen graphviz', 'apt install -y python-pip', 'pip install epydoc', 'apt-get -y install dpkg-dev',
                   'apt-get -y install libatlas-base-dev','apt-get install libunwind-dev']
        self.sdk_path=''
        self.option=-1
        self.cmd='python %s -u <username> -o <option> -d <sdk_directory_name>' % sys.argv[0].split('/')[-1]
        self.dir={'tcsim':'hg clone http://10.10.10.10:8000/merc_repos/v1_01/tcsim/ v1/tcsim',
                  'swtests':'hg clone http://10.10.10.10:8000/merc_repos/tc1000/swtests/ swtests',
                  'driver':'hg clone http://10.10.10.10:8000/merc_repos/tc1000/driver/ driver',
                  'openvx':'hg clone http://10.10.10.10:8000/merc_repos/tc1000/openvx/  openvx',
                  'compiler':'hg clone http://10.10.10.10:8000/merc_repos/v1_01/compiler/ compiler',
                  'opensrc':'hg clone http://10.10.10.10:8000/merc_repos/tc1000/opensrc/ opensrc',
                  'blas':'hg clone http://10.10.10.10:8000/merc_repos/v1_01/blas/ blas',
                  'dnn':'hg clone http://10.10.10.10:8000/merc_repos/v1_01/dnn_fmwk/ dnn_fmwk',
                  'hasm':'hg clone http://10.10.10.10:8000/merc_repos/v1_01/hasm/ hasm'}
        self.err_count=0
    get_arg=get_arg
    exe_cmds=exe_cmds
    sdk_dir=sdk_dir
    clone_repo=clone_repo
    check_repo=check_repo
    crt_soft_link=crt_soft_link
    crt_prefix_dir=crt_prefix_dir
    export_env=export_env
    build_clang=build_clang
    install_hipchat=install_hipchat
    
def main():
    tci=install_tci_sdk()
    if os.getuid()!=0:
        pr("Should be a root user to run this script\nGive sudo su and then execute the script")
        usage(tci.cmd)
    tci.get_arg()
    if tci.option==1:
        tci.exe_cmds()
        tci.sdk_dir()
        tci.clone_repo()
        tci.check_repo()
        tci.crt_soft_link()
        tci.crt_prefix_dir()
        tci.export_env()
    elif tci.option==2:
        tci.build_clang()
        tci.install_hipchat()
        pg('All SDK components Executed Successfully')
    else:  
        usage(tci.cmd)   
main()
