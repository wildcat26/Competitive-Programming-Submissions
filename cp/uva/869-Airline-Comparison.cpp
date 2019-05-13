#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int OFST = 65;

int counter = 0;
int comp[2][26];
int n, m;
vector <vector <int> > adj[2];
vector <bool> visited;

void dfs(int u, int parent, int parity) {
	visited[u] = true;
	comp[parity][u] = counter;
	for (auto v : adj[parity][u]) {
		if (visited[v] || v == parent)
			continue;
		dfs(v, u, parity); 
	}
	return;
}

void aux(int parity) {
	counter = 0; // IMP TODO
	visited.assign(N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i, -1, parity);
			counter++; // IMP TODO
		}
	}
	return;
}

void solve() {
	aux(0);
	aux(1);
	for (int i = 0; i < N; i++) {
		if (comp[0][i] != comp[1][i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

void read() {
	adj[0].assign(N, vector<int>());
	adj[1].assign(N, vector<int>());
	char U, V;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> U >> V;
		adj[0][int(U) - OFST].push_back(int(V) - OFST);
		adj[0][int(V) - OFST].push_back(int(U) - OFST);
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> U >> V;
		adj[1][int(U) - OFST].push_back(int(V) - OFST);
		adj[1][int(V) - OFST].push_back(int(U) - OFST);
	}
	return;
}

int main () {
	int tst;
	cin >> tst;
	while (tst--) {
		read();
		solve();
		if (tst != 0)
			cout << "\n";
	}
	return 0;
}
