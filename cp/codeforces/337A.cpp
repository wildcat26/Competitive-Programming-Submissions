#include <bits/stdc++.h>
using namespace std;
int main() {
 int n, i, m, minDiff = 1000, diff;
 scanf("%d %d", &n, &m);
 int A[m];
 for (i = 0; i < m; scanf(" %d", A + i++));
 sort(A, A + m);
 for (i = 0; i <= (m - n); i++) {
   diff = A[i + n - 1] - A[i];
   if (diff < minDiff)
   	minDiff = diff;
 }
 printf("%d\n", minDiff); 			
 return 0;
}

/* 4 5 6 6 7 8  (choose 3) */

