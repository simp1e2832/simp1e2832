#pragma once

class HeapHeap
{
private:
	int m_size;
	int m_capacity;
	int* m_node;

public:
	HeapHeap(int capacity);
	~HeapHeap();
	void add(int input);
	int pop();
	void print();

private:
	void swap(int index1, int index2);
};

