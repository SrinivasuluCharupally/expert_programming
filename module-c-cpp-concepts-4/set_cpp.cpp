#include <iostream>
#include <set>
using namespace std;

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

//  it=myset.find(1);
//	cout << " Find value = " << *it << endl;

const bool is_in = myset.find(10) != myset.end();
        cout << " Find value = " << is_in << endl;


/*  myset.erase (it);
  myset.erase (myset.find(40));

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
*/
  return 0;
}
