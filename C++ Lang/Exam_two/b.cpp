#include <bits/stdc++.h>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int testcases, array_size, number_of_query;

   cin>>testcases;

   for(int testcase=0; testcase<testcases; testcase++){
        cin>>array_size;
        cin>>number_of_query;
        
        int array[array_size];
        int qRes[number_of_query];

        for(int i=0; i<array_size; i++){
            cin>>array[i];
        }

        for(int i=0; i<number_of_query; i++){
            int lr, ur;

            cin>>lr;
            cin>>ur;

            int minVal = array[lr-1];
            for(int j=lr-1; j<ur; j++){
                if(minVal > array[j]){
                    minVal = array[j];
                }
            }

            qRes[i] = minVal;
        }

        cout<<"Case "<<testcase+1<<':'<<endl;
        for(int i=0; i<number_of_query; i++){
            cout<<qRes[i]<<endl;
        }
   }
   
  return 0;
}
