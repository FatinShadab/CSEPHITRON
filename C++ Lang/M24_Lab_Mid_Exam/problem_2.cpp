#include <bits/stdc++.h>

using namespace std;

int main(){
    int size_1, size_2;
    
    cin>>size_1;
    int array_1[size_1];

    for(int i=0; i<size_1; i++){
        cin>>array_1[i];
    }

    cin>>size_2;
    int array_2[size_2];

    for(int i=0; i<size_2; i++){
        cin>>array_2[i];
    }

    for(int i=0; i<size_2; i++){
        for(int j=0; j<size_1; j++){
            if(array_1[j] == array_2[i]){
                array_1[j] = -1;
            }
        }
    }

    for(int i=0; i<size_1; i++){
        if (array_1[i] >= 0) cout<<array_1[i]<<" ";
    }

    return 0;
}