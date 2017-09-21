// Henry Hsu
// CS 102
// Lab 1-3  Greet user

#include <iostream>

using namespace std;

int main()

{
	cout << "Hi there!  My name is Ali." << endl;
	cout << "What's your name?" << endl;
	string name_1; getline (cin, name_1);
	cout << "Hi " << name_1 << ", I'm happy to meet you!" << endl;
}