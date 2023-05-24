/*
    Problem Link : https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 2e9;

/*
    - state         : stone(n)
        -> cost of reaching n-th stone from 1st stone
    
    - recurrance    :
        -> stone(n) = for i = 1 to k:
                            min(
                                stone(n-i) + abs(h[n] - h[n-i])
                            ) 
    
    - base case     : stone(1) = 0
*/

int h[N], dp[N];

int stone(int n, int k){
    int ans = INF;

    if (n == 1){
        return 0;
    }

    if (dp[n] != -1){
        return dp[n];
    }

    for(int i = 1; i <= k; i++){
        if(n-i <= 0){
            break;
        }
        
        int candidate_ans = stone(n-i, k) + abs(h[n] - h[n-i]);
        ans = min(ans, candidate_ans);
    }

    dp[n] = ans;

    return dp[n];
}

int main(){
    int n, k;

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        dp[i] = -1;
        cin >> h[i];
    }

    cout << stone(n, k) << endl;
}