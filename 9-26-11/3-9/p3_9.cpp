
        
                #include <iostream>
                using namespace std;
        

        int main()
        {
                
                        double num1, num2, num3;
                        
                        cout << "Please input an unique numeric value for number 1: ";
                        cin >> num1;
                        cout << "Please input an unique numeric value for number 2: ";
                        cin >> num2;
                        cout << "Please input an unique numeric value for number 3: ";
                        cin >> num3;
                
                
                        double result = 0;
                        if (num1 > num2 && num1 > num3)
                        {
                                result = num1;
                        }
                        else if (num2 > num1 && num2 > num3)
                        {
                                result = num2;
                        }
                        else if (num3 > num1 && num3 > num2)
                        {
                                result = num3;
                        }
                
                
                        cout << "The largest number is: " << result;

                
        }
