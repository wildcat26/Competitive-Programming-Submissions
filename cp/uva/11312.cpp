#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
 if (b == 0)
 	return a;
 return gcd(b, a % b);
}

int main () {
 int c, n, l, r, t;
 unsigned long long int lcm = 1;
 int gcdd = 1, x = 0, y = 0, num;
 scanf(" %d", &c);
 while (c--) {
   scanf(" %d %d %d %d", &n, &l, &r, &t);
   gcdd = gcd(l, r);
   lcm = a / gcdd;
   lcm *= b;
   num = t - 1;
   if (num % gcdd == 0) {
   	x = ceil(num / r);
   	if (num % r == 0)
   		printf("%d\n", x);
   	else {
   		r*x;
   	}
   }
   else
   	printf("uh-oh!\n");
 }
 return 0;
}
