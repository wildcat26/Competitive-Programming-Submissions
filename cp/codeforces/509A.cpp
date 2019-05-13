#include <bits/stdc++.h>
using namespace std;
int main () {
 int n;
 scanf(" %d", &n);
 unsigned long long int a[n][n];
 for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
    	a[i][j] = 1;
    }
 }
 for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
    	a[i][j] = a[i - 1][j] + a[i][j - 1];
    }
 }
 cout << a[n-1][n-1] << "\n";
 return 0;
}
