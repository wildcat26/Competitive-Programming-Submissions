#include <bits/stdc++.h>
using namespace std;
int number[4];

inline void digit (int y) {
  number[0] = y % 10;
  number[1] = ((y - number[0]) / 10) % 10;
  number[2] = ((y - 10*number[1] - number[0]) / 100) % 10;
  number[3] = ((y - 100*number[2] - 10*number[1] - number[0]) / 1000) % 10;
 return;
}

int distinct(int pos) { // 0 if distinct
 for (int i = 0; i < 4; i++) {
 	if (i == pos);
 	else if (number[i] == number[pos])
 		return 1;
 }
 return 0;
}

int fullDistinct (int y) {
 digit(y);
 for (int i = 0; i < 4; i++) {
   if (distinct(i))
	return 1;	
 }
 return 0; // yes fully distinct
}


int main() {
 int num;
 scanf("%d", &num); 
 num += 1; 
while (fullDistinct(num)) {
  while (distinct(0)) {
    num += 1;
  }
  
}
 printf("%d\n", num);
 return 0;
}


/*
1 2 3 4 5 6 7 8 9
1000 1032, 1023!; 1000 
9000
*/
