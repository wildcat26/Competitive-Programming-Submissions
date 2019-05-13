#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <vector <int> > adj;
vector <bool> visited;
vector <vector <long long int > > matrix;

long long int LEN_LIMIT;
bool found;

void dfs (int u, int parent) { // from 1 -- N
	visited[u] = true;
	if (found)
		return;
	if (u == n - 1) {
		found = true;
		return;
	}
	long long int w;
	for (auto v : adj[u]) {
		w = matrix[u][v];
		if (v == parent)
			continue;
		if (!visited[v] and w >= LEN_LIMIT)
			dfs(v, u);
	}
	return;
}

void solve() {
	long long int  mid, beg = 1, end = (long long int)1e18;
	bool flag = false;
	while (beg <= end) {
		if (end == (1 + beg))
			flag = true;
		mid = (beg + end)/2;
		LEN_LIMIT = mid;
		found = false;
		visited.assign(n, false);
		dfs(0, -1);
		if (visited[n - 1])
			beg = mid + 1;
		else end = mid - 1;
		if (flag)
			break;
	}
	if (visited[n - 1])
		cout << mid << "\n";
	else cout << "-1\n";
	return;
}

void read () {
	cin >> n >> m;
	adj.assign(n, vector<int>());
	matrix.assign(n, vector<long long int >(n, 0));
	int x, y;
	long long int w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		x--; y--; // IMP TODO
		adj[x].push_back(y);
		adj[y].push_back(x);
		if (w > matrix[x][y]) {
			matrix[x][y] = w;
			matrix[y][x] = matrix[x][y];
		}
	}
	return;
}

int main () {
	int tst;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tst;
	while (tst--) {
		read();
		solve();
	}
	return 0;
}
