#include <iostream>
#include <string>

using namespace std;

void practice_cpp() {
	int age;
	cout << "Age? : ";
	cin >> age;

	int number;
	cout << "Number? : ";
	cin >> number;


	cout << "Name? : ";
	string name;
	cin.ignore();
	getline(cin, name);
	

	cout << "Address? : ";
	string address;
	cin >> address;

	cout << name << " " << age << " " << address << endl;
}