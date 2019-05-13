#include <bits/stdc++.h>
using namespace std;
int main () {
 int n, k, ans_j;
 scanf("%d %d", &n, &k);
 int a[n], cf[n], sum[n - k + 1];
 for (int i = 0; i < n; i++) {
 	scanf(" %d", a + i);
 	if (i == 0)
 		cf[0] = a[0];
 	else cf[i] = cf[i - 1] + a[i];
 }
 int min = 1000000000;
 for (int i = 0; i < n - k + 1; i++) {
 	if ((cf[i + k - 1] - cf[i] + a[i]) < min) {
 		min = (cf[i + k - 1] - cf[i] + a[i]);
 		ans_j = i + 1;
 	}
 }
 printf("%d\n", ans_j);
 return 0;
}
