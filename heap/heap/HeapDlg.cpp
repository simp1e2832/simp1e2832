#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
	HeapHeap HeapInstance(8);

	HeapInstance.print();

	cout << endl;

	HeapInstance.add(5);
	HeapInstance.print();
	cout << endl <<  "add" << endl;
	HeapInstance.add(3);
	HeapInstance.print();
	cout << endl << "add" << endl;
	HeapInstance.add(7);
	HeapInstance.print();
	cout << endl << "add" << endl;
	HeapInstance.add(1);
	HeapInstance.print();
	cout << endl << "add" << endl;
	HeapInstance.add(2);
	HeapInstance.print();
	cout << endl << "add" << endl;
	HeapInstance.add(6);
	HeapInstance.print();
	cout << endl << "add" << endl;
	HeapInstance.add(4);
	HeapInstance.print();
	cout << endl;

	cout << endl << "pop" << endl;
	HeapInstance.pop();
	HeapInstance.print();
	cout << endl << "pop" << endl;
	HeapInstance.pop();
	HeapInstance.print();
	cout << endl << "pop" << endl;
	HeapInstance.pop();
	HeapInstance.print();
	cout << endl << "pop" << endl;
	HeapInstance.pop();
	HeapInstance.print();
	cout << endl << "pop" << endl;
	HeapInstance.pop();
	HeapInstance.print();
	cout << endl << "pop" << endl;
	HeapInstance.pop();
	HeapInstance.print();
	cout << endl;

	return 0;
}