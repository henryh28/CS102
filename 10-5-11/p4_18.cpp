


#include <iostream>
using namespace std;


int main()
{
 
         int target_number;
         cout << "Please enter a positive integer: ";
         cin >> target_number;                   // store user input into variable
         if (cin.fail())
         {
                 cout << "Your input was not an integer." << endl;
                 return 1;
         }
         
         if (target_number < 0)
         {
                 cout << "Please input only positive integers." << endl;
                 return 1;
         }
 
 
 bool prime_status;
 for (int prime_numbers = 2; prime_numbers <= target_number; prime_numbers++)
         {
         prime_status = true;
         for(int i = 2; i < prime_numbers; i++)
                 {
                         if (prime_numbers % i == 0) prime_status = false;
                 }
         if (prime_status) cout << prime_numbers << endl;
 }
  
}

