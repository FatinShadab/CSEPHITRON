#include <bits/stdc++.h>

using namespace std;

int first_index(string &str, char ch){
    for(int i=0; i<str.length(); i++){
        if(str[i] == ch){
            return i;
        }
    }
    return -1;
}

int last_index(string &str, char ch){
    for(int i=str.length()-1; i>=0; i--){
        if(str[i] == ch){
            return i;
        }
    }
    return -1;
}

int main(){
    string str;
    cin>>str;

    int stIdx = first_index(str, 'A');
    int edIdx = last_index(str, 'Z');

    cout<<(edIdx-stIdx)+1<<endl;

    return 0;
}