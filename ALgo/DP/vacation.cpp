/*
    PB Link : https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

/*
    - state: fun(x, y) -> maximum happiness till day-n
                            if we pick task-x on day-n

    - recurrance: fun(n, x) = max (
        fun(n-1, y) + happiness[n][x] // where x != y
    )

    - base case: fun(1, x) = happiness[n][x]
*/
int happiness[N][4], dp[N][4];

int fun(int day, int task){
    int can_gain_happiness;
    int max_happiness_gain = INT_MIN;

    // base case
    if (day == 1){
        return happiness[day][task];
    }

    if (dp[day][task] != -1){
        return dp[day][task];
    }

    for (int prev_task = 1; prev_task <= 3; prev_task++){
        if (prev_task != task){
            can_gain_happiness = fun(day - 1, prev_task) + happiness[day][task];

            if (can_gain_happiness > max_happiness_gain){
                max_happiness_gain = can_gain_happiness;
            }
        }
    }

    dp[day][task] = max_happiness_gain;

    return dp[day][task];
}

int main(){
    int n;
    int candidate_ans;
    int max_happiness = INT_MIN;

    scanf("%d", &n);

    for (int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            dp[i][j] = -1;
            scanf("%d", &happiness[i][j]);
        }
    }

    for (int i=1; i<=3; i++){
        candidate_ans = fun(n, i);

        if (candidate_ans > max_happiness){
            max_happiness = candidate_ans;
        }
    }

    printf("%d\n", max_happiness);

    return 0;
}