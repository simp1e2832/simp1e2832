#include <iostream>
#include <string>
using namespace std;

void find_mine_game()
{
	// 1. 전처리 과정에서 padding을 추가하는 방법

	//recieve input and make the map using 2중 pointer
	int m;
	int n;
	cin >> m >> n;
	char** map_2dimension = new char* [102];
	for (int i = 0; i < 102; i++) {
		map_2dimension[i] = new char[102];
	}
	for (int i = 0; i < 100; i++) {
		map_2dimension[i][0] = '.';
		map_2dimension[0][i] = '.';
		map_2dimension[m + 1][i] = '.';
		map_2dimension[i][n + 1] = '.'; /// 이 부분은 실행이 안되는 이유는?
	}
	for (int i = 0; i < m; i++) {
		cin >> map_2dimension[i + 1] + 1;
	}
	cout << endl;



	//make a new map for count the mines
	int** map_count = new int* [100];
	for (int i = 0; i < 100; i++) {
		map_count[i] = new int[100];
		for(int j = 0; j <100; j++){
			map_count[i][j] = 0;
		}
	}
	int sum;
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (map_2dimension[i][j] == '*') {
				map_count[i - 1][j - 1]++;
				map_count[i - 1][j]++;
				map_count[i - 1][j + 1]++;
				map_count[i][j - 1]++;
				map_count[i][j] = 10;
				map_count[i][j + 1]++;
				map_count[i + 1][j - 1]++;
				map_count[i + 1][j]++;
				map_count[i + 1][j + 1]++;
			}
		}
	}



	//print 2 dimension map to check if pointer work well
	for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			cout << map_count[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < m+2; i++) {
		for (int j = 0; j < n+2; j++) {
			cout << map_2dimension[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (map_count[i][j] > 9) {
				cout << '*';
			}
			else {
				cout << map_count[i][j];
			}
		}
		cout << endl;
	}





	/*
	char* map_2dimention[20000];
	char ** ppnt = &map_2dimension;
	*/

	return;
}