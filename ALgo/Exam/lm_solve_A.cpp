/*
    Problem Link : https://www.eolymp.com/en/problems/992
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, inp; cin >> n;
    int numberOfOnes = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> inp;
            numberOfOnes += inp;
        }
    }

    cout<<numberOfOnes/2<<endl;

    return 0;
}