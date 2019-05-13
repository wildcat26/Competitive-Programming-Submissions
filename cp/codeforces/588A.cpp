#include <bits/stdc++.h>
using namespace std;
int main () {
 int n, mini = 101, cost = 0;
 scanf(" %d", &n);
 int a[n], p[n], til[n];
 for (int i = 0; i < n; i++) {
  scanf(" %d %d", a + i, p + i);
  if (p[i] < mini)
  	til[i] = p[i], mini = p[i];
  else
  	til[i] = mini;
 }
 for (int i = 0; i < n; i++)
    cost += (til[i] * a[i]);
  printf("%d\n", cost);
 return 0;
}
