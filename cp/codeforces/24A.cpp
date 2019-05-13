#include <bits/stdc++.h>
using namespace std;
int main () {
 int n;
 scanf(" %d", &n);
 int arr[n][3];
 for (int i = 0; i < n; i++)
   scanf(" %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
 int s1[n + 1], s2[1 + n];
 s1[0] = arr[0][0];
 s1[1] = arr[0][1];
 s2[0] = s1[1];
 s2[1] = s1[0];
 int cost1, cost2;
 cost1 = 0;
 cost2 = arr[0][2];
 for (int i = 2; i <= n; i++) {
   for (int j = 0; j < n; j++) {
   	if (arr[j][0] == s1[i - 1] && arr[j][1] != s1[i - 2]) {
   		s1[i] = arr[j][1];
   	}
   	else if (arr[j][1] == s1[i - 1] && arr[j][0] != s1[i - 2]) {
  		s1[i] = arr[j][0];
  		cost1 += arr[j][2];
  	}
  }
 }
  for (int i = 2; i <= n; i++) {
   for (int j = 0; j < n; j++) {
   	if (arr[j][0] == s2[i - 1] && arr[j][1] != s2[i - 2]) {
   		s2[i] = arr[j][1]; 
   	}
   	else if (arr[j][1] == s2[i - 1] && arr[j][0] != s2[i - 2]) {
  		s2[i] = arr[j][0];
  		cost2 += arr[j][2];
  	}
  }
 }
 printf("%d\n", min(cost1, cost2));
 return 0;
}
 
