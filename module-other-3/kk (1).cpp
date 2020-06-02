// operator 

class add {
	int a;
  public:
	add(int v) : a(v) {} 
	add() {}
	add(const add& right) {
		a = *right.a;
	}

	add& operator+(const add& second_right) {
		add first_right;
		first_right.a = a + second_right.a;
		return first_right;
	}
};

int main() {
	add x(3), y(4) ;
	add z;
	z = x+y;

	add copy_of_x = x;
}
	


