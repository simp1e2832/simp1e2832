#include <iostream>
using namespace std;

void swap_myself(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return;
}