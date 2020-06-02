// binary heap for min heap

// source http://www.geeksforgeeks.org/binary-heap/

// insert runtime O(log n);
// delete root runtime O(log n)

#include<iostream>
using namespace std;

class MinHeap {
	int *heap_arr;
	int capacity;
	int heap_current_size;
  public:
	MinHeap(int cap) {
		heap_current_size = 0;
		capacity = cap;
		heap_arr = new int[cap];
	}
	
	
	void MinHeapify(int i) {// this for re-arranging elements in case root is deleted, else not required...
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if(l < heap_current_size && heap_arr[l] < heap_arr[i])
			smallest = l;
		if(r < heap_current_size && heap_arr[r] < heap_arr[smallest])
			smallest = r;
		if(smallest != i) {
			swap(&heap_arr[i], &heap_arr[smallest]);
			MinHeapify(smallest);
		}
	}
	
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i +1 ); }
	int right(int i) { return (2*i + 2); }
	
	void insert(int value) {
		if(heap_current_size == capacity) {
			cout << " over flow" << endl;
			return;
		}

		heap_current_size++;
		int i = heap_current_size - 1;
		heap_arr[i] = value;
		while(i != 0 && heap_arr[parent(i)] > heap_arr[i]) {
			swap(&heap_arr[i], &heap_arr[parent(i)]);
			i = parent(i);
		}
	}
	
	int getMin() { return heap_arr[0];}

	int removeMin() {
		if(heap_current_size <=0) return 0;
		if(heap_current_size == 1) { 
			heap_current_size--;
			return heap_arr[0];
		}

		int root = heap_arr[0];
		heap_arr[0] = heap_arr[heap_current_size -1];
		heap_current_size--;
		MinHeapify(0);
		return root;
	}

	void swap(int* a, int* b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	void display() {
	        for(int i = 0; i < 5; ++i)
                cout << heap_arr[i] << endl;
	}
};

			
int main() {
	MinHeap heap(11);
	int arr[] = {12, 3, 5, 7, 19};
	for(int i = 0; i < 5; ++i)
		heap.insert(arr[i]);
	heap.display();
//        for(int i = 0; i < 5; ++i)
//		cout << arr[i] << endl;	
}

	

