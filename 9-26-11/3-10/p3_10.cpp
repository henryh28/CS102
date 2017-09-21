

        
                #include <iostream>
                using namespace std;
        

        int main()
        {
                
                        string string1, string2, string3;
                        
                        cout << "Please input an unique text value for string 1: ";
                        cin >> string1;
                        cout << "Please input an unique text value for string 2: ";
                        cin >> string2;
                        cout << "Please input an unique text value for string 3: ";
                        cin >> string3;
                
                
                        string primary, secondary, tertiary;
                        if (string1 > string2 && string1 > string3)
                        {
                                primary = string1;
                                if (string2 > string3)
                                {
                                        secondary = string2;
                                        tertiary = string3;
                                }
                                else
                                {
                                        secondary = string3;
                                        tertiary = string2;
                                }
                        }
                        
                        if (string2 > string1 && string2 > string3)
                        {
                                primary = string2;
                                if (string1 > string3)
                                {
                                        secondary = string1;
                                        tertiary = string3;
                                }
                                else
                                {
                                        secondary = string3;
                                        tertiary = string1;
                                }       
                        }
                        
                        if (string3 > string1 && string3 > string2)
                        {
                                primary = string3;
                                if (string1 > string2)
                                {
                                        secondary = string1;
                                        tertiary = string2;
                                }
                                else
                                {
                                        secondary = string2;
                                        tertiary = string1;
                                }
                        }
                
                
                        cout << "The ordered output is: " << tertiary << " " << secondary << " " << primary << ".";

                
        }
