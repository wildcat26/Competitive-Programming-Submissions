#include<iostream>
#include<cmath>
unsigned long long int euclidGCD(unsigned long long int, unsigned long long int); 
unsigned long long int cal2BN(unsigned long long int, unsigned long long int, unsigned long long int); 
using namespace std;
int main(){
int t; 
unsigned long long int a, b, n; 
cin >> t; 
for (int x = 0; x < t; x++){
 cin >> a >> b >> n; 
 if (b == 1) 
    cout << (2 % (a - 1)) << "\n"; 
 else if (a == b){
   unsigned long long int intermed = cal2BN(a, 0, n); 
   cout << euclidGCD(intermed, a) % (1000000007) << "\n";
 } 
 else {
   unsigned long long int intermed = cal2BN(a, b, n); 
   cout << (euclidGCD(intermed, (a - b))) % (1000000007) << "\n"; 
 }
}
 return 0;
}

unsigned long long int euclidGCD (unsigned long long int x, unsigned long long int y){
 if (x == 0) 
	return y; 
 unsigned long long int gcd = euclidGCD((y % x), x);  
  return gcd; 
} 

unsigned long long int cal2BN(unsigned long long int a, unsigned long long int b, unsigned long long int n){
 /* calculating (b^n)%(a-b) iteratively */ 
 if (a == (b + 1)) 
	return 1; 
 unsigned long long int num, group, left, leftNum = 1, qnty = n;
 num = (b % (a - b)); 
  while (qnty != 1){
    group = (unsigned long long int) floor((log(a - b)/log(num))); 
    left = n % group; 
    leftNum *= (unsigned long long int) pow(num, left); 
    leftNum = leftNum  % (a - b); 
    num = (unsigned long long int) pow(num, group); 
    num = num % (a - b);  
    qnty = ((n - left)/ group); 
 }
  return ((2 * (a - b)) * (num % (a - b)) * (leftNum % (a - b))) % (a - b); 
}
