#include <bits/stdc++.h>

using namespace std;

int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    int testcases;
    cin>>testcases;

    for(int testcase=0; testcase<testcases; testcase++){
        int size, query;
        cin>>size;
        cin>>query;

        int arr[size];
        int qRes[query];
        //int preSum[size];

        for(int i=0; i<size; i++){
            cin>>arr[i];
        }
        
        //preSum[0] = arr[0];
        //for(int i=1; i<size; i++){
        //    preSum[i] = arr[i] + preSum[i-0];
        //}

        for(int j=0; j<query; j++){
            int cmd;
            cin>>cmd;

            if(cmd == 1){
                int idx;
                cin>>idx;
                qRes[j] = arr[idx];
                arr[idx] = 0;
            }
            if(cmd == 2){
                int money, idx;
                cin>>idx;
                cin>>money;

                arr[idx] = arr[idx] + money;
                qRes[j] = -1;
            }
            if(cmd == 3){
                int iIdx, jIdx;
                cin>> iIdx;
                cin>> jIdx;

                if(jIdx == 0 && iIdx == 0){
                    qRes[j] = arr[0];
                }
                else{
                    int money = 0;
                    for(int i=iIdx; i<=jIdx; i++){
                        money = money + arr[i];
                    }
                    qRes[j] = money;
                }
            }
            
        }

        cout<<"Case "<<testcase+1<<":"<<endl;
        for(int i=0; i<query; i++){
            if(qRes[i] != -1){
                cout<<qRes[i]<<endl;
            }
        }
    }

    return 0;
}