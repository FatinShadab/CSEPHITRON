#include<bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j= i-1;
        while(arr[j]>key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    cout<<"\nArray after insertion sort - ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
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

    insertion_sort(arr, size);
    cout<<endl;

    return 0;
}