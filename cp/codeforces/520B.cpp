#include <bits/stdc++.h>
using namespace std;
int main () {
int n, m;
scanf(" %d %d", &n, &m);
if (n >= m)
	printf("%d\n", n - m);
else {
 	int step1 = 0, step2 = 0;
 	int temp = n;
 	while (temp >= m) {
 		temp *= 2;
 		++step1;
 	}
 	step1 += (temp - m);
 	step2 += (n - ceil(m / 2) + 1)
 		
}
 return 0;
}
