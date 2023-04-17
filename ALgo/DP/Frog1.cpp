/*
    Problem Link -> https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 5;
int h[N], dp[N];

int min_stone_distance(int n){
    if (n <= 1){
        return 0;
    }

    if (dp[n] != -1){
        return dp[n];
    }

    int distance_1 = min_stone_distance(n-1) + abs(h[n] - h[n-1]);

    if (n == 2){
        dp[n] = distance_1;
        return dp[n];
    }

    int distance_2 = min_stone_distance(n-2) + abs(h[n] - h[n-2]);

    dp[n] = min(distance_1, distance_2);

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> h[i];
        dp[i] = -1;
    }

    cout << min_stone_distance(n) << endl;

    return 0;
}