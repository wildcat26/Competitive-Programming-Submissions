#include <iostream>
using namespace std;
int main(){
 int n, i;
 scanf("%d", &n);
 int A[n], B[n];
 for (i = 0; i < n; scanf(" %d", A + i++));
 for (i = 0; i < n; i++)
 	B[A[i] - 1] = i + 1;
 for (i = 0; i < n; printf("%d ", B[i++]));
 return 0;
}
