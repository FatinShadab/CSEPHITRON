#include <iostream>
#include <string>
using namespace std;
  
int main()
{
    string str;
  
    cout << "Please enter your name: \n";
    getline(cin, str);
    cout << "Hello, " << str
         << " welcome to GfG !\n";
  
    return 0;
}