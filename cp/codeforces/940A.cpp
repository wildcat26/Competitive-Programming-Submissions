#include <bits/stdc++.h>
using namespace std;
int countt = 0;
int solve(int arr[], int size, int d) {
//for (int i = 0; i < size; i++)
	//printf("%d ", arr[i]);
//printf("\n");
 if ((arr[size - 1] - arr[0]) <= d || size == 1) {
 	//printf("countt here = %d\n", countt);
 	return countt;
 }
 if ((arr[size - 2] - arr[0]) < (arr[size - 1] - arr[1])) { // remove last
 	countt++;
 	return solve(arr, size - 1, d);
 }
 else if ((arr[size - 2] - arr[0]) > (arr[size - 1] - arr[1])) { // remove first
 	countt++;
 	return solve(arr + 1, size - 1, d);
 }
 else {
 //	cout << "else \n";
 	int temp1 = countt;
 	countt = 0;
  	int t1 = solve(arr, size - 1, d) + 1;
  	countt = 0;
  	int t2 = solve(arr + 1, size - 1, d) + 1;
 	countt = temp1;
// 	cout << "t1 "<< t1 << " t2 " << t2 << "\n";
 	countt += min(t1, t2);
 	return countt;
// 	cout << "countt " << countt << " \n";
 }

}

int main () {
int n, d;
scanf("%d %d", &n, &d);
set <int> st; int t;
for (int i = 0; i < n; i++) {
	cin >> t;
	st.emplace(t);
}
int fsize = st.size();
int a[fsize]; int i = 0;
for (auto it = st.begin(); it != st.end(); it++) {
	printf("%d ", *it);
	a[i++] = *it;
}
printf("\n");
int ans = solve(a, fsize, d);
 printf("%d\n", ans);
 return 0;
}
