/*
    Problem Link -> https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 5;
int h[N], dp[N];

int main(){
    int n;
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> h[i];
    }

    // handle the base case
    dp[1] = 0;

    // loop through the states
    for (int i=2; i<=n; i++){
        if (i == 2){
            dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
            continue;
        }

        dp[i] = min(
            dp[i-1] + abs(h[i] - h[i-1]),
            dp[i-2] + abs(h[i] - h[i-2])
        );
    }

    cout << dp[n] << endl;

    return 0;
}