#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> visited;
map<int, int> mp1; // vertex to temp_int
map<int, int> mp2; // temp_int to vertex
bool first = true;

void dfs(int u) {
 visited[u] = 1; // set visited to 1
 map<int, int>::iterator p = mp2.find(u);
 if (first == true) {
 	printf("%d", p->second);
 	first = false;
 }
 else printf(" %d", p->second); 
 for (vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
 	if (visited[*it] == 0)
 		dfs(*it);
 }
 return;
}

int main () {
	int n;
	scanf(" %d", &n);
	int e[n][2]; // n edges, n + 1 vertices
	set<int> s;
	adj.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &e[i][0], &e[i][1]);
		s.insert(e[i][0]);
		s.insert(e[i][1]);
	}
	int k = 0;
	for (set<int>::iterator x = s.begin(); x != s.end(); x++) {
		mp1.insert({*x, k});
		mp2.insert({k++, *x});
	}
	for (int i = 0; i < n; i++) {
		map<int, int>::iterator x = mp1.find(e[i][0]);
		map<int, int>::iterator y = mp1.find(e[i][1]);
		adj[x->second].push_back(y->second);
		adj[y->second].push_back(x->second);
	}
	for (int i = 0; i <= n; i++) {
		if (adj[i].size() == 1) {
			dfs(i);
			printf("\n");
			break;
		}
	}
 return 0;
}
