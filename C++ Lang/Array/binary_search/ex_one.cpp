#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int x, int lb, int ub){
    // the arr must be shorted in ascending order.
    
    int idx = -1;
    int mid = (lb+ub)/2;

    if (x == arr[mid]){
        idx = mid;
    }
    else if (x > arr[mid]){
        binarySearch(arr, x, mid+1, ub);
    }
    else{
        binarySearch(arr, x, lb, mid-1);
    }

    return idx;
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

    int idx = binarySearch(
        array,
        target_value,
        0,
        size-1
    );

    cout<<idx;

    return 0;
}