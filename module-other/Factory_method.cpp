// soruce for the exmple http://www.bogotobogo.com/DesignPatterns/factorymethod.php
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class button {
  public:
	virtual void paint() { cout << " button class" << endl; }
};

class window : public button {
  public:
	void paint() { cout << " windows class" << endl; }
};

class door : public button {
  public:
	 void paint() { cout << " door class" << endl; }
};

class GUIFactory {
  public:
	virtual button* create(char *) = 0;
};
class Factory : public GUIFactory {
  public:
	button* create(char *type) {
		if(strcmp(type,"window") == 0) return new window;
		else return new door;
	}
};

int main() {
 door d;
 d.paint();
 window w;
 w.paint();
 button b;
 b.paint();
 button *bp = new door;
 bp->paint();
 Factory *Gp = new Factory;
 bp = Gp->create("window");
 bp->paint();
 
// GUIFactory *Gf;
// button *bp;

}
