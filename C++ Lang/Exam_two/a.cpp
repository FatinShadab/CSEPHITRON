#include <bits/stdc++.h>

using namespace std;

int main(){
    int count = 0;

    for(int i=0; i<4; i++){
        int input;
        cin>>input;
        if (input > 10 || input == 10){
            count ++;
        }
    }

    cout<<count;

    return 0;
}