# cook your dish here
# cook your dish here
import re
list = ["dog dot", "do don't", "dumb-dumb", "no match"]

# Loop.
for element in list:
    # Match if two words starting with letter d.
    m = re.match("(d\w+)\W(d\w+)", element) # output will be dog/do/dump if you put (d\w+)
    # See if success.
    if m:
        print(m.groups())
    k = re.search(r"dot", element)
    if k:
        print(k.group()) # should be k.group(), not groups() because it's not list format

kk = "helo2"
final = re.findall("\D", kk)
if final:
    print (final)

xx = "guru99,education is fun"
r1 = re.findall(r"^\w+",xx)
print(r1)

xx = "guru99,education is fun"
r1 = re.findall(r"^\w+", xx)
print((re.split(r'\s','we are splitting the words')))
print((re.split(r's','split the words')))

================
output
================
('dog', 'dot')
dot
('do', 'don')
('dumb', 'dumb')
['h', 'e', 'l', 'o']
['guru99']
['we', 'are', 'splitting', 'the', 'words']
['', 'plit the word', '']
