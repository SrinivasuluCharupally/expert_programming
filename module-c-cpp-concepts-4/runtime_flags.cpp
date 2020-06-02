#include <iostream>
#include <string>
using namespace std;

bool debug=false;

int main(int argc, char* argv[]) {
//cout << argv[2] << argv[1] << endl;
if(string(argv[1]) == "on")
//if(string(argv[1]) == "--debug=on" || argv[0] == "--debug=on")
debug=true;
cout << "debug details " << debug << endl;
}
