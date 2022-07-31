#include<bits/stdc++.h>

using namespace std;

int main(){
    int unique = 3;
    int brushs[3];

    for (int i=0; i<3; i++){
        cin>>brushs[i];
    }

    for (int i=0; i<2; i++){
        if (brushs[i] == brushs[i+1]){
            unique--;
        }
    }

    if (brushs[0] == brushs[2]){
        if (unique > 1){
            unique--;
        }
    }

    cout<<unique;

    return 0;
}