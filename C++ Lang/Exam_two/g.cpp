#include <bits/stdc++.h>

using namespace std;

int main()  
{  
    int N;
    int R;
    int sum=0;
    int temp;    

    cin>>N;    
    temp = N;

    while(N > 0){    
        R = N % 10;    
        sum = (sum*10) + R;    
        N = N / 10;    
    }

    if(temp==sum){
        cout<<"Yes"<<endl;   
    }    
     
    else{
        cout<<"No"<<endl;   
    }

  return 0;  
}  