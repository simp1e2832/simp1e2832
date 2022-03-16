#include <iostream>
#include <tchar.h>

using namespace std;
void practice_casting()
{
	char str = 'D';
	wchar_t wstr = 'D';
	double aaa = (double)str;
	double waaa = (double)wstr;
	cout << "aaa : " << aaa << ", str : " << str << endl;
	cout << "waaa : " << waaa << ", wstr : " << wstr << endl;
}