#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main() {
char str[101], rev[101];
scanf("%s", str);
scanf("%s", rev);
reverse(rev, rev + strlen(rev));
if (strcmp(rev, str) == 0)
	printf("YES\n");
else printf("NO\n");
 return 0;
}
