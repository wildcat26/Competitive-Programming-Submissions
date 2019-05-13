#include <bits/stdc++.h>
using namespace std;
int main() {
 int t, i, j;
 scanf("%d", &t);
 int n;
 while (t--) {
   scanf("%d", &n);
   int x[n], y[n];
   int dist[n][n];
   for (i = 0; i < n; i++) 
  	scanf(" %d", (x + i));
   for (i = 0; i < n; i++) 
  	scanf(" %d", (y + i));
   for (i = 0; i < n; i++) {
    	for (j = 0; j < n; j++) {
		dist[i][j] = min(abs(x[i] - x[j]), abs(y[i] - y[j]));
		cout << dist[i][j] << " ";
	}
     cout << "\n";
   }
 }
 return 0;
}
