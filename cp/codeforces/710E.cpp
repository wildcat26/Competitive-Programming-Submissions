#include <bits/stdc++.h>
using namespace std;
int main () {
 int n, x, y;
 scanf(" %d %d %d", &n, &x, &y);
 int cost = x; // reached 1 from 0, no other choice
 int now = 1;
 while (now <= (n / 2)) {
  if (y < (now * x))
  	cost += y;
  else if (now <= n)
   	cost += (now * x);
  now *= 2;
 }
 cost += min((n - now) * x, y + ((2 * now - n) * x));
 printf("%d\n", cost);
 return 0;
}
