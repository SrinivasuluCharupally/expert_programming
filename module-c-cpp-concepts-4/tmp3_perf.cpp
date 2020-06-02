#include<iostream>
using namespace std;

typedef struct packet {
	int i, j;
	float f;
//	int x=0;
	long l;
	int k;
	long m;
} packet_t;

int main() {
	packet_t pkt[1000000];
	for(int itr = 0; itr < 1000000; itr++) {
		pkt[itr].i = itr;
		pkt[itr].j = itr;
                pkt[itr].f = itr;
                pkt[itr].l = itr;
                pkt[itr].k = itr;
                pkt[itr].m = itr;
         //       pkt[itr].j = itr;
	}

}
