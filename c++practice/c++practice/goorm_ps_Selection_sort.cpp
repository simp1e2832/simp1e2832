#include <iostream>

using namespace std;

void Selection_sort() {
	int number;
	int step;
	cin >> number >> step;
	int array[100000];
	for (int i = 0; i < number; i++) {
		cin >> array[i];
	}

	int temp;
	int min;
	int min_index;
	for (int i = 0; i < step; i++) {
		if (i == number - 1) {
			break;
		}
		min = 0;
		temp = array[i];
		min_index = i;
		for (int j = i + 1; j < number; j++) {
			if (array[j] < min) {
				min = array[j];
				min_index = j;
			}
		}
		array[i] = min;
		array[min_index] = temp;
	}

	for (int i = 0; i < number; i++) {
		cout << array[i] << " ";
	}
	return;
}