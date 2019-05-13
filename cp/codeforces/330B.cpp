#include <bits/stdc++.h>
using namespace std;
int main () {
 int n, m, a, b;
 scanf("%d %d", &n, &m);
 int arr[n];
 for (int i = 0; i < n; arr[i++] = 0);
 for (int i = 0; i < m; i++) {
 	scanf(" %d %d", &a, &b);
 	arr[a - 1] = 1;
 	arr[b - 1] = 1;
 }
 int node = 0;
 for (int i = 0; i < n; i++) {
   if (arr[i] == 0) {
   	node = i + 1;
   	break;
   }
 }
 printf("%d\n", n - 1);
 for (int i = 0; i < n; i++) {
   if (i != (node - 1))
	   printf("%d %d\n", node, i + 1);
 }
 return 0;
}
