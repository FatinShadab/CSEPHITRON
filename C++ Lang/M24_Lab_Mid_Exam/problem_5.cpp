#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    int sum = 0;
    cin>>size;

    int mid = size/2;
    int matrix[size][size];

    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            cin>>matrix[r][c];
        }
    }
    //cout<<endl;
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            if (r < mid){
                if (r == 0 && (c <= mid || c == size-1)){
                    sum += matrix[r][c];
                   // cout<<matrix[r][c]<<" ";
                }
                else if (c == mid || c == size-1){
                    sum += matrix[r][c];
                    //cout<<matrix[r][c]<<" ";
                }
            }
            else if (r > mid){
                if (r == size-1 && (c >= mid || c == 0)){
                    sum += matrix[r][c];
                    //cout<<matrix[r][c]<<" ";
                }
                else if (c == mid || c == 0){
                    sum += matrix[r][c];
                    //cout<<matrix[r][c]<<" ";
                }
            }
            else{
                sum += matrix[r][c];
                //cout<<matrix[r][c]<<" ";
            }
        }
        //cout<<endl;
    }
    //cout<<endl;
    //cout<<"Sum :"<<sum<<endl;
    cout<<sum;

    return 0;
}