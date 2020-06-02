#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area() {return width*height;}
     ~Rectangle();
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}
 Rectangle::~Rectangle ()
{
//delete(p);
}

int main () {
  Rectangle rect;
  Rectangle* p = new Rectangle;	
  p->set_values (3,5);
  rect.set_values (3,4);
  cout << "area: " << rect.area();
  cout << "area: " << p->area();
  delete(p);
  return 0;
}
