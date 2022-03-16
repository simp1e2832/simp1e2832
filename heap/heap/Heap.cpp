#include "Heap.h"
#include <iostream>

using namespace std;

HeapHeap::HeapHeap(int capacity)
{
	this->m_capacity = capacity;
	m_size = 0;
	m_node = new int[this->m_capacity];
}

HeapHeap::~HeapHeap()
{
	delete this->m_node;
}


void HeapHeap::add(int input)
{
	if (this->m_size >= this->m_capacity)
	{
		cout << "Heap is full already!" << endl;
	}
	else
	{
		int i = this->m_size;
		this->m_node[this->m_size] = input;
		this->m_size++;
		while (i != 0 && this->m_node[i] < this->m_node[(i + 1) / 2 - 1])
		{
			swap(i, (i + 1) / 2 - 1);
			i = (i + 1) / 2 - 1;
		}
	}
}

int HeapHeap::pop()
{
	if (this->m_size == 0)
	{
		cout << "There's nothing to pop!" << endl;
	}
	else
	{
		int number = this->m_node[0];
		int i = 0;
		this->m_node[0] = this->m_node[m_size - 1];
		this->m_size--;
		while (this->m_size - 1 >= i * 2 + 2) 
		{
			int smaller;
			if (i * 2 + 1 == this->m_size - 1) {
				smaller = i * 2 + 1;
			}
			else
			{
				if (this->m_node[i * 2 + 1] < this->m_node[i * 2 + 2])
				{
					smaller = i * 2 + 1;
				}
				else smaller = i * 2 + 2;
			}
			
			if (this->m_node[smaller] < this->m_node[i])
			{
				swap(i, smaller);
				i = smaller;
			}
			else break;
			/*
			if (this->m_node[i] > this->m_node[i * 2 + 1])
			{
				swap(i, i * 2 + 1);
				i = i * 2 + 1;
			}
			else if (this->m_node[i] > this->m_node[i * 2 + 2])
			{
				swap(i, i * 2 + 2);
				i = i * 2 + 2;
			}
			else break;
			*/
		}
		return number;
	}
}

void HeapHeap::print()
{
	if (this->m_size == 0)
	{
		cout << "There's nothing to print" << endl;
	}
	else
	{
		int number = 0;
		int line = 1;
		for (int i = 0; i < this->m_size; i++)
		{
			if (number == line)
			{
				cout << endl;
				line = line * 2 + 1;
			}
			cout << this->m_node[i] << " ";
			number++;
		}
	}
}

void HeapHeap::swap(int index1, int index2)
{
	int temp = this->m_node[index1];
	this->m_node[index1] = this->m_node[index2];
	this->m_node[index2] = temp;
}

/*
Class HeapHeap
{
public:
	
	HeapHeap(int capacity)
	{
		this->m_capacity = capacity;
		m_size = 0;
		m_node = new int[this->m_capacity];
	}

	~HeapHeap()
	{
		delete this->m_node;
	}
	
	void add(int input)
	{
		if (this->m_size >= this->m_capacity)
		{
			cout << "Heap is full already!" << endl;
		}
		else
		{
			int i = this->m_size;
			this->m_node[this->m_size] = input;
			this->m_size++;
			while (i != 0 || this->m_node[i] < this->m_node[i / 2])
			{
				swap(i, i / 2);
				i /= 2;
			}
		}

	}
	void pop(int index)
	{}
	void print()
	{}

private:
	void swap(int index1, int index2)
	{
		int temp = this->m_node[index1];
		this->m_node[index1] = this->m_node[index2];
		this->m_node[index2] = temp;
	}
};
*/