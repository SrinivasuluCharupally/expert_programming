#include<iostream>

extern "C" void welcom() {
	std::cout << "Welcome to so file" << std::endl;
}

extern "C" int max(int a, int b) {
	return a>b?a:b;
}
