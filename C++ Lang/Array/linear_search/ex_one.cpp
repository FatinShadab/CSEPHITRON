#include <bits/stdc++.h>

using namespace std;

void linear_search(int array[], int array_size, int target_value){
    for(int i=0; i<array_size; i++){
        if (array[i] == target_value){
            cout<<target_value<<" is found in index "<<i<<endl;
        }
    }
}


int main(){
    int size;

    cout<<"Enter the array size - ";
    cin>>size;

    int array[size];

    cout<<"\nEnter the array elements - "<<endl;
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    int target_value;
    cout<<"Enter the value you want to search - "<<endl;
    cin>>target_value;

    //linear search
    linear_search(array, size, target_value);

    return 0;
}