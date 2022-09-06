#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin>>m;
    cin>>n;

    int matrix[m][n];

    for(int r=0; r<m; r++){
        for(int c=0; c<n; c++){
            cin>>matrix[r][c];
        }
    }

    for(int r=0; r<m; r++){
        for(int c=0; c<n; c++){
            for(int r2=0; r2<m; r2++){
                for(int c2=0; c2<n; c2++){
                    if (c == c2 && r == r2){
                        continue;
                    }
                    else{
                        if (matrix[r2][c2] == matrix[r][c]){
                            matrix[r2][c2] = -1;
                        }
                    }
                }
            }
        }
    }

    cout<<endl;
    for(int r=0; r<m; r++){
        for(int c=0; c<n; c++){
            cout<<matrix[r][c]<<" ";
        }
        cout<<endl;
    }

    return 0;
}