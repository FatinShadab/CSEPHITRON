/*
The gcd() function in this link calculates gcd of two positive integers
Rewrite the function using recursion.
*/

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}

int gcd_re(int a, int b){
  if (b == 0)
    return a;

  return gcd_re(b, a%b);
}

int main(){

  int a, b;
  scanf("%d %d", &a, &b);

  printf("%d %d\n", gcd(a, b), gcd_re(a, b));

  main();

  return 0;
}