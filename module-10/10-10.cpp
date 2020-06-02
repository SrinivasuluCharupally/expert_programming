// Rank from Stream: Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of a number x (the number of values less than or equal to x). Implement the data structures and algorithms to support these operations. That is, implement the method track(int x), which is called when each number is generated, and the method getRankOfNumber(int x), which returns the number of values less than or equal to x(not including x itself).



// source http://petercrushcode.blogspot.in/2016/06/reading-integer-streams-and-return-n-th.html

#include<iostream>
using namespace std;

struct node {
  int v;
  int lc;
  node * l;
  node * r;
  node(int value): v(value), lc(0), l(0), r(0){}
};

class NumberStream {
  node *root=NULL;
public:
  NumberStream() {}
  void track(int x)
  {
    node *prev = 0, *cur = root;
    if (!root)
    {
      root = new node(x);
      return;
    }

    while(cur)
    {
      prev = cur;
      if (cur->v >= x)
      {
        cur->lc++;
        cur = cur->l;
      } else {
        cur = cur->r;
      }
    }
    if (prev->v >= x)
    {
      prev->l = new node(x);
    } else {
      prev->r = new node(x);
    }
  }
int get_rank(int x)
  {
    int count = 0;
    node * cur = root;

    while (cur)
    {
      if (cur->v == x)
      {
        count = cur->lc + count;
        break;
      } else if ( cur->v < x) {
        count = count + cur->lc + 1;
        cur= cur->r;
      } else {
        cur = cur->l;
      }
    }
    return count;
  }
private:
  node *root;
};

int main()
{
  NumberStream s;
  s.track(5);
  s.track(1);
  s.track(4);
  s.track(4);
  s.track(5);
  s.track(9);
  s.track(7);
  s.track(9);
  s.track(13);
  s.track(3);

  cout<<"rank of 1 : "<<s.get_rank(1)<<endl;
  cout<<"rank of 3 : "<<s.get_rank(3)<<endl;
  cout<<"rank of 4 : "<<s.get_rank(4)<<endl;
  return 1;
}
