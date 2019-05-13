#include<iostream>
using namespace std;
int main(){
 int n, sum = 0;
 cin >> n; 
 for (int i = 5; i >= 1; i--){
  sum += (n / i);
  n = n % i;
 }
 cout << sum << "\n";
 return 0;
}
