#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
using pii = pair <int, int>;

// d[i][j] = wt of min edge on i-->j with 1, 2 ... k as intermediate vertices

int n, m, q;
vector <vector <pii> > adj;
vector <vector <int> > d;

void floyd() {
	d.assign(n, vector<int>(n, INF));
	int v, w, temp;
	for (int u = 0; u < n; u++) {
		d[u][u] = 0;
		for (auto pp : adj[u]) {
			v = pp.first;
			w = pp.second;
			d[u][v] = min(d[u][v], w); // can have multiple edges, k = 0
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp = max(d[i][k - 1], d[k - 1][j]);
				d[i][j] = min(temp, d[i][j]);
			}
		}
	}
	return;
}

void query() {
	int src, dest;
	while (q--) {
		cin >> src >> dest;
		src--, dest--; // IMP!
		if (d[src][dest] == INF)
			cout << "no path\n";
		else cout << d[src][dest] << "\n";
	}
	return;
}

void read() {
	int x, y, w, cnt = 1;
	while (cin >> n >> m >> q, (n || m || q)) {
		adj.assign(n, vector<pii>());
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> w;
			x--; y--; // IMP!
			adj[x].push_back(pii(y, w));
			adj[y].push_back(pii(x, w));
		}
		if (cnt == 1)
			cout << "Case #" << cnt << "\n";
		else cout << "\nCase #" << cnt << "\n";
		cnt++; 
		floyd();
		query();
	}
	return;
}

int main () {
	read();
	return 0;
}
