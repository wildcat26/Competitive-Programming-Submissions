#include <bits/stdc++.h>
using namespace std;
int main () {
 int k;
 int a[12];
 scanf(" %d", &k);
 for (int i = 0; i < 12; scanf(" %d", a + i++));
 sort(a, a + 12);
 int i = 11, sum = 0;
 while (sum < k && i >= 0) {
 	sum += a[i];
 	--i;
 }
 if (sum >= k)
	 printf("%d\n", 11 - i); 
 else printf("-1\n");
 return 0;
}
