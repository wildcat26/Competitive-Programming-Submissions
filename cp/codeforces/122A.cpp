#include <iostream>
using namespace std;

int main(){
 int n;
 int A[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
 scanf("%d", &n);
 for (int i = 0; i < 14; i++)
 	if (n % A[i] == 0)
 		return 0*printf("YES\n");
 return 0*printf("NO\n");
}
