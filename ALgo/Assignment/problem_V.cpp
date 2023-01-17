/*
The int_to_binary() function in this link takes a positive integer as parameter
and returns its binary representation as string.
Rewrite the function using recursion.
*/

#include <bits/stdc++.h>

using namespace std;
/*
// Normal
string int_to_binary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary = '0' + binary;
        }
        else {
            binary = '1' + binary;
        }
        decimal /= 2;
    }
    return binary;
}
*/

// with recursion
string int_to_binary(int decimal) {
    static string binary = "";

    if (!(decimal)){
        return binary;
    }

    if (decimal % 2 == 0) {
        binary = '0' + binary;
    }
    else {
        binary = '1' + binary;
    }
    
    return int_to_binary(decimal / 2);
}

int main(){

    int num;
    scanf("%d", &num);

    cout<<"base 10 : "<<num<<", base 2 : "<<int_to_binary(num)<<endl;

    return 0;
}