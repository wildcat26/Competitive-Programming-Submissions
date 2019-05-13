#include <bits/stdc++.h>
using namespace std;
int main () {
 int n, sum = 0, temp;
 scanf("%d", &n);
 for (int i = 0; i < n; i++) {
 	scanf(" %d", &temp);
 	sum += temp;
 }
 float ans = (float) sum /  n;
 cout << setprecision(10) << ans << "\n";
 return 0;
}
