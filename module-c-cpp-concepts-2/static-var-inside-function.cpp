#include<iostream>
using namespace std;

void inc() {
static int i =0;
//i++;
cout << " helo " << ++i << endl;
}

int main(int argc, char* argv[]) {

for(int k =0; k <10; k++ ) {
	inc();
}
}


