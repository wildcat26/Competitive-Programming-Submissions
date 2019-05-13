#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main () {
 int n;
 scanf("%d", &n);
 int a[n];
 for (int i = 0; i < n; i++)
 	scanf(" %d", a + i);
 sort(a, a + n);
 unsigned long long int ans = 0;
 for (int i = 0; i < n; i++)
 	ans += abs(i + 1 - a[i]);
 cout << ans << "\n";
 return 0;
}
