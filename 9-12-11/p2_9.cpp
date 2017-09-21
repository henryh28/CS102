

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
        cout << "Please enter a phone number in 10 digit format: " << endl;
        string phone_number;
        cin >> phone_number;

        
                string area = phone_number.substr(0,3);
        ;
        cout << "Area      code  : " << setw(13) << area << endl;

        
                string prefix = phone_number.substr(3,3);
        ;
        cout << "Prefix    number: " << setw(13) << prefix << endl;
        
        
                string suffix = phone_number.substr(6,4);
        ;
        cout << "Suffix    number: " << setw(13) << suffix << endl;

        cout << "Formatted output: " << "(" + area + ")" + prefix + "-" + suffix << endl; 
}
