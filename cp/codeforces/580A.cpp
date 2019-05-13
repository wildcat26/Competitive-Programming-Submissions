#include <bits/stdc++.h>
using namespace std;
int main() {
 int n, i, max = -1, j = 0, count = 0;
 scanf("%d", &n);
 int A[n];
 for (i = 0; i < n; scanf(" %d", A + i++));
 for (i = 0; i < n;) {
   j = i + 1;
     while (A[j - 1] <= A[j] && j < n) {
  //   printf("%d ", A[j]);
     j++;
     count++;
     }
   i = j;
   if (max < count)
	max = count;
  count = 0;
  //printf("\n");
 }
 printf("%d\n", max + 1);
 return 0;
}
