
        
                #include <iostream>
                #include <string>
                #include <cstdlib>
                using namespace std;
        
        
        string get_bar_code()
        {
                string bar_code;
                cout << "Please enter a valid USPS barcode: ";  
                return bar_code;
        }
        
        
        void print_zip_code(string bar_chunk)
        {
                if (bar_chunk == ":::||")
                        cout << "1";
                else if (bar_chunk == "::|:|")
                        cout << "2";
                else if (bar_chunk == "::||:")
                        cout << "3";
                else if (bar_chunk == ":|::|")
                        cout << "4";
                else if (bar_chunk == ":|:|:")
                        cout << "5";
                else if (bar_chunk == ":||::")
                        cout << "6";
                else if (bar_chunk == "|:::|")
                        cout << "7";
                else if (bar_chunk == "|::|:")
                        cout << "8";
                else if (bar_chunk == "|:|::")
                        cout << "9";
                else if (bar_chunk == "||:::")
                        cout << "0";
                else
                {
                        cout << "That is not a valid bar code.";
                        exit(1);
                }
        }
        



int main()
{
        string bar_code = get_bar_code();
        string bar1, bar2, bar3, bar4, bar5;
        bar1 = bar_code.substr(0,5);
        bar2 = bar_code.substr(5,5);
        bar3 = bar_code.substr(10,5);
        bar4 = bar_code.substr(15,5);
        bar5 = bar_code.substr(20,5);
        
        cout << "The zip code associated with your barcode is: ";
        
        print_zip_code(bar1);
        print_zip_code(bar2);
        print_zip_code(bar3);
        print_zip_code(bar4);
        print_zip_code(bar5);

}
