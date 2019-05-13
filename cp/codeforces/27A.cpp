#include <bits/stdc++.h>
using namespace std;
int main () {
int n;
scanf("%d", &n);
int a[n];
for (int i = 0; i < n; scanf(" %d", a + i++));
sort(a, a + n);
if (a[0] > 1)
	printf("1\n");
else {
for (int i = 0; i < n - 1; i++) {
 if ((a[i + 1] - a[i]) > 1) {
 	cout << a[i] + 1 << "\n";
 	return 0;
 }
}
cout << a[n - 1] + 1 << "\n";
}
 return 0;
}
