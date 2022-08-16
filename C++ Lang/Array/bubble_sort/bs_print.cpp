#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size){
    for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

void bubble_short_ase(int arr[], int size){
    for(int i=1; i<size; i++){
        cout<<"\n"<<i<<" Itaration :\n"<<endl;
        for(int j=0; j<size-1; j++){
            cout<<"     step ("<<j+1<<") : ";
            printArray(arr, size);
            if (arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            cout<<" => ";
            printArray(arr, size);
            cout<<endl;
        }
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

    bubble_short_ase(arr, size);

    return 0;
}