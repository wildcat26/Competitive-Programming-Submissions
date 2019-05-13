#include<stdio.h>
int main(){
int n; 
scanf("%d", &n); 
if (n & 1)
  printf("-1\n"); 
else {
  for (int i = 1; i <= n; i += 2){
    printf("%d ", ++i); 
    printf("%d ", --i);
  } 
    printf("\n"); 
 }
 return 0; 
}
