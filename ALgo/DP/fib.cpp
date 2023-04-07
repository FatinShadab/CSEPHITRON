#include <bits/stdc++.h>
using namespace std;
#define MAX_N 101

long long cache[MAX_N];


int fib(int n){
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);
}

long long fib_opt(long long n){
    if (n <= 2) return cache[n];

    if (cache[n] != 0){
        return cache[n];
    }

    cache[n] = fib_opt(n-1) + fib_opt(n-2);

    return cache[n];
}

int main(){

    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 1;

    cout<<fib(3)<<endl;
    cout<<fib(5)<<endl;
    
    // can't give output after 20s 
    // cout<<fib(50)<<endl;

    cout<<fib_opt((long long) 50)<<endl;

    for (int i=0; i<=50; i++){
        cout<<i<<" : "<<cache[i]<<"\n";
    }

    return 0;
}