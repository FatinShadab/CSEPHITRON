#include <bits/stdc++.h>

using namespace std;

int maxAmongThreeNormal(int a, int b, int c){
    if (a >= b && a >= c) return a;
    else if (b >= a && b>= c) return b;
    else return c;
}

template<typename T> T maxAmongThreeTemplate(T a, T b, T c){
    if (a >= b && a >= c) return a;
    else if (b >= a && b>= c) return b;
    else return c;
}
 

int main(){

    cout<< maxAmongThreeNormal(1, 2, 3)<<endl;
    cout<< maxAmongThreeTemplate<int>(10, 20, 30)<<endl;
    cout<< maxAmongThreeTemplate<float>(10.10, 10.01, 9.99)<<endl;
    cout<< maxAmongThreeTemplate<char>('a', 'b', 'c')<<endl;

    return 0;
}