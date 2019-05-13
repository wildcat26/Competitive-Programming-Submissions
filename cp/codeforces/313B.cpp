#include <bits/stdc++.h>
using namespace std;
int main () {
 char s[100001];
 int m, l, r;
 scanf("%s", s);
 int len = strlen(s);
 int arr[len];
 arr[0] = 0;
 scanf("%d", &m);
 for (int i = 0; i < len - 1; i++) {
   if (s[i + 1] == s[i])
   	arr[i + 1] = arr[i] + 1;
   else arr[i + 1] = arr[i];
 }
 while (m--) {
  scanf(" %d %d", &l, &r);
  printf("%d\n", arr[r - 1] - arr[l - 1]);
 }
 return 0;
}
