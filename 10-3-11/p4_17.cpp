

#include <iostream>
using namespace std;


int main()
{
        
                int target_number;
                cout << "Enter a positive integer: ";
                cin >> target_number;

                if (cin.fail())
                {
                        cout << "Your input was not an integer." << endl;
                        return 1;
                }
                
                if (target_number < 0)
                {
                        cout << "Input error.  Please input only positive integers." << endl;
                        return 1;
                }
        
        
                int prime = 2;                          
                if( prime > target_number ) cout << target_number << " has no prime factors." << endl;
                while (prime <= target_number)  
                {
                        if( target_number % prime != 0) 
                        {
                                prime++;                
                        }
                        else
                        {
                                target_number = target_number / prime;  
                                cout << prime << endl;  
                        }
                }
         
}

