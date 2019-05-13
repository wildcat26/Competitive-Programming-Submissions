#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main () {
 string s1, s2, f;
 cin >> s1 >> s2 >> f;
 int init[26], finals[26];
 for (int i = 0; i < 26; init[i] = 0, finals[i++] = 0);
 for (int i = 0; i < (s1.length() + s2.length()); i++) {
 	if (i < s1.length())
	 	++init[(s1[i] - 'A')];
 	else ++init[(s2[i - s1.length()] - 'A')];
 }
 for (int i = 0; i < f.length(); i++)
 	++finals[(f[i] - 'A')];	
 for (int i = 0; i < 26; i++) {
 	if (init[i] != finals[i]) {
 		printf("NO\n");
		return 0;
	}
 }
 printf("YES\n");
 return 0;
}
