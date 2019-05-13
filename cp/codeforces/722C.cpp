#include <bits/stdc++.h>
int main () {
 int n;
 scanf(" %d", &n);
 int arr[n], perm[n], dest[n];
 int cf[n];
 for (int i = 0; i < n; i++) {
   scanf(" %d", arr + i);
   dest[i] = 0;
   if (i == 0)
   	cf[0] = arr[0];
   else cf[i] = cf[i - 1] + arr[i];
 }
 int l1 = 0, r1 = n - 1;
 int l2 = 0, r2 = n - 1;
 int max1, max2;
 int dummy1, dummy2;
  for (int i = 0; i < n; i++) {
   scanf(" %d", perm + i);
   dest[perm[i] - 1] = 1;
   if (perm[i] > l1 + 1 && perm[i] < r1 + 1) {
   	int temp1 = cf[perm[i] - 2] - cf[l1] + arr[l1];
   	int temp2 = cf[r1] - cf[perm[i] - 1];
	int bigger = 2;
	if (temp1 > temp2)
		bigger = 1;
	if (max(temp1, temp2) < max2) {
		dummy1 = l1, dummy2 = r1;
		l1 = l2, r1 = r2;
		max1 = max2;
	   if (bigger == 1) 
		l2 = dummy1, r2 = perm[i] - 2;
	   else  
	   	l2 = perm[i], r2 = dummy2; 	
	  
	   max2 = cf[r2] - cf[l2] + arr[l2];
	}
   	else if (bigger == 1) { // temp1 biggest
   	   if (temp2 > max2) {
   	   	
   	   }
   	}
   	else { // temp2 biggest
   	   if (temp1 > max2)
   	} 	
   }
   else if (perm[i] > l2 + 1 && perm[i] < r2 + 1) {
    
   }		
  }
 return 0;
}

// (l, r]
