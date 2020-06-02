// circular array: Circular Array: Implement a CircularArray class that supports an array-like data structure which can be acciciently rotated. If possible, the class should use a generic type (also called a template), and should support iteration via the standard for (Obj o : circularArray) notatio

// source book

#include<iostream>
using namespace std;


template <class T> 
class CircularArray {
	T* items_;
	int size_;
	int positionFilling_;
	int noOfElementsRotated_;
 public:
 	CircularArray(int size) {
		size_ = size;
		items_ = new T[size];
		positionFilling_ = 0;
		noOfElementsRotated_ = 0;
	}
	void set(T item);
	T get(int position);
	void rotate(int r);
	void iterator(CircularArray<T> itr);
};

template <class T>
void CircularArray<T>::set(T item) {
	*(items_+positionFilling_) = item;
	++positionFilling_;
}

template <class T>
T CircularArray<T>::get(int index) {
	if(noOfElementsRotated_ != 0) { 
		int getposition = size_  - noOfElementsRotated_ + index;  
		if(getposition >= size_) { 
			index = index - noOfElementsRotated_ ; 
		}  
		else index = getposition;
	}

      return *(items_+ index);
}

template <class T>
void CircularArray<T>::rotate(int r) {
	noOfElementsRotated_ = r;
}

template <class T>
void CircularArray<T>::iterator(CircularArray<T> itr) {
		
		for(int index = 0 ; index < size_; ++index) {
			int finalIndex_;
			int getposition = size_ - noOfElementsRotated_ + index;
			if(getposition >= size_) finalIndex_ = index - noOfElementsRotated_;
			else finalIndex_ = getposition;
			cout << "  " << *(items_ + finalIndex_) << endl;
		}
	        cout << "iterator 1 item  =  " << itr.get(1) << endl;
}


int main() {
	CircularArray<int> c(4);
	c.set(10); c.set(2); c.set(30); c.set(40);
	cout << "item 0 = " << c.get(0) << endl;
	c.rotate(1);
        cout << "item 0 after rotation by 1 =  " << c.get(0) << endl;
        cout << "item 1 after rotation by 1 =  " << c.get(1) << endl;
	c.iterator(c);
}


