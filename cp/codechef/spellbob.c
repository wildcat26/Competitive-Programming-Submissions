#include<stdio.h>
int main(){
int index, i, j, t, sum_b, sum_o;  scanf("%d", &t); 
int s[2][3];  
int b[3], o[3]; 
char ch, temp; 
for (int x = 0; x < t; x++){
 for (i = 0; i < 2; i++){
  scanf("%c", &temp); 
   for (j = 0; j < 3; j++){
     scanf("%c", &ch); 
     s[i][j] = (int) (ch - 'a'); 
   }  
 }  
  for (i = 0; i < 3; i++) 
     b[i] = o[i] = 0; 
 for (j = 0; j < 3; j++){
 	if (s[0][j] == 1 || s[1][j] == 1)
	   b[j] = 1; 
	if (s[0][j] == 14 || s[1][j] == 14)
	   o[j] = 1; 
  }
 sum_b = b[0] + b[1] + b[2]; 
 sum_o = o[0] + o[1] + o[2]; 

 if (sum_b < 2)
   printf("no\n");

 else if (sum_b == 2){
   for (i = 0; i < 3; i++)
     if (b[i] == 0) index = i;  
   if (o[index] == 1) 
	printf("yes\n"); 
   else printf("no\n"); 
 }

 else {
   if (sum_o >= 1)
	printf("yes\n"); 
   else printf("no\n"); 
 }
}
 return 0;
}
