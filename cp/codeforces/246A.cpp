#include <bits/stdc++.h>
using namespace std;
int main () {
 int count = 0, n, k, temp;
 scanf(" %d %d", &n, &k);
 for (int i = 0; i < n; i++) {
 	scanf(" %d", &temp);
 	if ((temp + k) <= 5)
 		count++;
 }
 printf("%d\n", count / 3);	
 return 0;
}
