#include <bits/stdc++.h>

using namespace std;

void bubble_short_ase(int arr[], int size){
    for(int i=1; i<size; i++){
        int flag = 0;
        cout<< "iteration no : "<< i<< endl;
        for(int j=0; j<size-i; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            //print the array
            for(int i=0; i<size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            }
            if (flag == 0){
                break;
        }
    }

    cout<<"\nAfter bubble short (asending) - ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int size;

    cout<<"Enter the array size - ";
    cin>>size;

    int arr[size];

    cout<<"\nEnter the array elements - ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    bubble_short_ase(arr, size);
    cout<<endl;

    return 0;
}