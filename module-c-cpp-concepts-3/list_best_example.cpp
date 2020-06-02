#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;

int main() {
    list<int> li;
    li.push_back(10);
    cout << li.front() << endl;
    
    list<int*> li_sp;
    int* p = new int;
    *p = 20;
    li_sp.push_back(p);
    cout << li_sp.front() << endl;
    cout << *(li_sp.front()) << endl;
    cout << (*li_sp.front()) << endl;
    
    list<int> *adj;
    adj = new list<int>[2];
    adj[0].push_back(50);
    adj[0].push_back(60);
    adj[1].push_back(70);
    cout << adj[0].front() << endl;
    list<int> tmp = adj[1];
    cout << tmp.front() << endl;
}

//output
10
0x2b385506ac50
20
20
50
70
