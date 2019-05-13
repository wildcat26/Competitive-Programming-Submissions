#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
   if (a.first != b.first)
   	return a.first < b.first;
   else return a.second < b.second;
}

int main () {
 int n;
 scanf("%d", &n);
 vector <pair <int, int>> vec;
// vec.resize(n); 
 int a, b;
 for (int i = 0; i < n; i++) {
 	scanf(" %d %d", &a, &b);
 	vec.push_back(make_pair(a, b));
 }
 sort(vec.begin(), vec.end(), comp);
 for (int i = 0; i < (n - 1); i++)	
 	if (vec[i].second > vec[i + 1].second)
 		return 0*printf("Happy Alex\n");		
 return 0*printf("Poor Alex\n");	
}
