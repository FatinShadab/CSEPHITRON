#include <bits/stdc++.h>

using namespace std;

int max_ele(int array[], int size){
    int max = array[0];

    for (int i=1; i<size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }

    return max;
}

int main(){

    int size;
    cin>>size;

    int array[size];

    for (int i=0; i<size; i++){
        cin>>array[i];
    }

    int frq_size = max_ele(array, size)+1;
    int frq[frq_size] = {0};

    for (int i=0; i<size; i++){
        frq[array[i]] = frq[array[i]] + 1;
        //cout<<array[i]<<" "<<frq[array[i]]<<endl;
    }

    for (int i=0; i<frq_size; i++){
        if (frq[i] != 0){
            cout<<i<<" => "<<frq[i]<<endl;
        }
    }

    return 0;
}