#include <bits/stdc++.h>
using namespace std;
int main () {
 int n, i, counter = 1, max = 1;
 scanf("%d", &n);
 int arr[n][2], diff[n][2];
 for (i = 0; i < n; i++)
 	scanf(" %d %d", &arr[i][0], &arr[i][1]);
 for (int i = 0; i < n - 1;) {
   if ((arr[i][0] == arr[i + 1][0]) && (arr[i][1] == arr[i + 1][1])) {
   	while ((arr[i][0] == arr[i + 1][0]) && (arr[i][1] == arr[i + 1][1])) {
   		i++;
   		counter++;
   		if (i == n - 1)
   			break;
   	}
   	if (max < counter)
   		max = counter;
   }
   else {
    counter = 1;
    i++;
   }
 }
 printf("%d\n", max);
 return 0;
}
