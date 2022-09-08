#include <bits/stdc++.h>

using namespace std;

void task(){
    int size;
    cin>>size;

    int dayIncome[size];
    int dayExpense[size];

    // takes incomes of a day from user 
    for (int i=0; i<size; i++){
        cin>>dayIncome[i];
    }

    // takes expenses of a day from user 
    for (int i=0; i<size; i++){
        cin>>dayExpense[i];
    }

    int num_of_queries;
    cin>>num_of_queries;
    int query_results[num_of_queries];

    // takes queries from user then calculate the result and stores it
    int user_query;
    for (int query=0; query < num_of_queries; query++){

        cin>>user_query;

        int total_income_till_ith_day = 0;
        int total_expense_till_ith_day = 0;

        for (int i=0; i<=user_query; i++){
            total_income_till_ith_day += dayIncome[i];
            total_expense_till_ith_day += dayExpense[i];
        }

        if ((total_income_till_ith_day - total_expense_till_ith_day) >= 0){
            query_results[query] = 1;
        }
        else{
            query_results[query] = 0;
        }
         
    }

    for (int result=0; result < num_of_queries; result++){
        cout<<query_results[result]<<" ";
    }
    cout<<endl;

}

int main(){
    int testcase;
    cin>>testcase;

    for (int tcase=0; tcase < testcase; tcase++){
        task();
    }

    return 0;
}