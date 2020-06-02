#include<iostream>
#include<stdio.h>
#include<stdlib.h> // getenv & setenv decleared here...
#include<time.h>
#include<ctime>
#include<unistd.h>
using namespace std;


int main(int argc, char* argv[]) {

	setenv("LD_PRELOAD", "./libmax_intercepter.so",1);
	for(int i = 1; i <argc; ++i) {
		string arg = argv[i];
		if(arg == "-t") {
			cout << "Tracing enabled..." << endl;
			 cout << "     Running test : " << arg << endl;
                           // ShellExecute(NULL, "open", "./arg", NULL, NULL, SW_SHOWDEFAULT);
                        //char comand[100];
                        //sprintf(comand, "./%s", argv[i]);
			 string next = argv[i+1];
			 if(next == "-p") system(argv[i+2]);
			 else system(argv[i+1]);

		}

		else { if(arg == "-p") {
                        cout << "Profiling enabled..." << endl;
			clock_t begin = clock();
			system(argv[i+1]); usleep(30);
			clock_t end = clock();
			double time = (double)(end-begin)/CLOCKS_PER_SEC;
			cout <<  "     Profiling time = " << time << "ms" << endl;

			return 0;
                	}	
		//	else { cout << "     Running test : " << arg << endl;
			   // ShellExecute(NULL, "open", "./arg", NULL, NULL, SW_SHOWDEFAULT);
			//char comand[100];
			//sprintf(comand, "./%s", argv[i]);
		//		system(argv[i]);

//			}
		}
	}
	char* env = getenv("LD_PRELOAD");
//	cout << env << endl;

//    ShellExecute(NULL, "open", "./arg", NULL, NULL, SW_SHOWDEFAULT);

	
}
