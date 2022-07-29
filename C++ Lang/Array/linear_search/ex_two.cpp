#include <bits/stdc++.h>

using namespace std;

int user_cmd(void){
    char con;
    cout<<"Do you want to search (Y/N)? - ";
    cin>>con;

    if (toupper(con) == 'Y'){
        return 1;
    }
    else{
        return 0;
    }
}

void linear_search(int array[], int array_size, int target_value){
    int found_any = 0;
    for(int i=0; i<array_size; i++){
        if (array[i] == target_value){
            cout<<"Founded in index "<<i<<endl;
            found_any++;
        }
    }
    if (found_any == 0){
        cout<<"NOT FOUND!";
    }
}

int main(){
    
    int size;
    int do_search;

    cout<<"Enter the array size - ";
    cin>>size;

    int array[size];

    cout<<"\nEnter the array elements - "<<endl;
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    do_search = user_cmd();

    while (do_search){

        int target_value;
        cout<<"\nEnter the value you want to search - "<<endl;
        cin>>target_value;

        linear_search(array, size, target_value);

        do_search = user_cmd();
    }

    return 0;
}