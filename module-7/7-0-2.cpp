#include<iostream>
#include<vector>

using namespace std;

class b { };
class d : public b{ 
    vector<b*> bp;
 public:
    void fun(b* b) {
        bp.push_back(b);
    }
    
};

int main() {
   b* bp = new d;
    d* obj = new d;
    d* obj1 = new d;
    obj->fun(bp);
    obj1->fun(bp);
	return 0;
}
