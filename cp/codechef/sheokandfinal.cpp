#include<cmath>
#include<iostream>
int powTwo(unsigned long int); 
unsigned long int Min (unsigned long int, unsigned long int, unsigned long int); 

using namespace std; 
int main(){
int t;  cin >> t; 
int bIndex, sIndex; 
unsigned long int n, two_k, two_s, bef, aft, mid, min = 0;  
for (int x = 0; x < t; x++){
  cin >> n; 
 if (n == 1) 
	cout << "2\n"; 
 else {
   bIndex = powTwo(n);
   two_k = (unsigned long int) pow(2, bIndex); 
   if (two_k == n) cout << "1\n"; 
   else {
   sIndex = powTwo((n - (unsigned long int) pow(2, bIndex)));  
   two_s = (unsigned long int) pow(2, sIndex); 
bef = two_k + two_s; 
mid = two_k + 2*two_s; 
aft = 2*two_k + 1; 
      if (sIndex + 1 == bIndex) {
           if (n - bef < aft - n) 
               min += (n - bef); 
       else min += (aft - n); 
     }
      else
           min += Min(n - bef, mid - n, aft - n);   
   cout << min << "\n"; 
  } 
}
min = 0; 
}
 return 0; 
}

int powTwo(unsigned long int x){
 int num = 0; 
 while (x != 1){
   x = x >> 1; 
   num++; 
 }
 return num; 
}

unsigned long int Min (unsigned long int x, unsigned long int y, unsigned long int z){
 unsigned long int d = x; 
 unsigned long int e = y; 
if (x < y)
    d = y, e = x; 
if (z < e) 
   return z; 
else return e; 
}
