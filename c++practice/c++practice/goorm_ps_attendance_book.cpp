#include <iostream>
#include <cstring>
using namespace std;

void attendance_book() {
	char input[100];
	cin >> input;
	char* pnt = input;
	int result = 99;
	
	while (pnt + 1 != NULL) {
		result = strncmp(pnt, pnt + 1, 1);
		cout << "result = " << result << endl;
		if (strncmp(pnt, pnt + 1, 1) > 0) {
			break;
		}
		pnt++;
	}
	
	while (*(pnt + 1) != NULL) {
		cout << *pnt << ", " << *(pnt +1) << endl;
		*pnt = *(pnt + 1);
		pnt++;
	}
	*pnt = '\0';

	cout << "input = " << input << endl;
	return;
}