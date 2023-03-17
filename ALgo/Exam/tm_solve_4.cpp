/*
    Question :
    ----------
    Given a positive integer n, write a recursive function 
    to print all combinations of numbers between 1 and n 
    having sum n.

    For example, 
        For n = 5, the following combinations are possible: 
            { 5 }
            { 1, 4 }
            { 2, 3 }
            { 1, 1, 3 }
            { 1, 2, 2 }
            { 1, 1, 1, 2 }
            { 1, 1, 1, 1, 1 }
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> comb;

void printComb(){
    int count = 0;
    cout<<"{ ";
    for (int ele : comb){
        count++;
        cout << ele;
        if (count < comb.size()){
            cout << ",";
        }
    }
    cout<<" }"<<endl;
}

void showAllcombs(int n, int idx){
    if (n == 0){
        printComb();
    }

    for (int i = idx; i <= n; i++){
        comb.push_back(i);
        showAllcombs(n-i, i);
        comb.pop_back();
    }
}

int main(){
    int n;
    cin >> n;

    showAllcombs(n, 1);

    return 0;
}