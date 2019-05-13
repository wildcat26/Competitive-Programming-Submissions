#include <bits/stdc++.h>
using namespace std;
int main () {
 int n, t;
 scanf(" %d %d", &n, &t);
 int a[n - 1];
 for (int i = 0; i < n - 1; i++)
 	scanf(" %d", a + i);
 int index = 1;
 while (index < t) {
    index += a[index - 1];
 }
 if (index == t)
 	printf("YES\n");
 else printf("NO\n");
 return 0;
}
