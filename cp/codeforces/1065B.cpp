#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main () {
int n;
unsigned long long int m;
scanf("%d %lld", &n, &m);
if (n == 1) {
	printf("1 1\n");
	return 0;
}
if (n <= 2*m)
	printf("0");
else printf("%d", n - 2*m);
/*
if (n >= (m + 1))
	printf(" %d\n", n - m - 1);
else printf(" %d\n", 0); */
int i, root = ceil(sqrt(2*m));
printf("root %d ", root);
i = root;
while ((i * (i - 1)) - (2 * m)) {
  i--;
}
printf("i %d\n", i);
n > i ? printf(" %d\n", n - i - 1) : printf(" 0\n"); 
 return 0;
}

/*
55 66 ... 60
11 12 ... 12 */
