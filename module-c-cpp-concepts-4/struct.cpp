#include <iostream>
using namespace std;

struct ss {
int i;
char c;
};
typedef struct tt {
int i;
} tt_t;

int main() {
struct ss k;
tt_t k2;
k2.i = 34;
k.i = 10;
k.c = 'a';
cout << k.i << "  " << k.c << endl;
cout << k2.i << endl;
}

