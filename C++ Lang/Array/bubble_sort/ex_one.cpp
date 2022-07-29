#include <bits/stdc++.h>

using namespace std;

void bubble_short_ase(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout<<"After bubble short (asending) - ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubble_short_dese(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if (arr[j]<arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout<<"After bubble short (desending) - ";
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
    bubble_short_dese(arr, size);

    return 0;
}