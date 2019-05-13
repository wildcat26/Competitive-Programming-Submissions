#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF =  (int)1e9;

int n, m;
vector <vector <pii> > adj;
vector <vector <int> > d;
vector <int> max_d;

void floyd() {
	int v, w;
	d.assign(n, vector<int>(n, INF));
	for (int u = 0; u < n; u++) {
		d[u][u] = 0;
		for (auto pp : adj[u]) {
			v = pp.first;
			w = pp.second;
			d[u][v] = min(d[u][v], w); // k = 0th phase
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][k] == INF or d[k][j] == INF)
					continue;
				d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
			}
		}
	}
	max_d.assign(n, -INF);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			max_d[i] = max(max_d[i], d[i][j]);
	}
	return;
}

int solve() {
	int rally, dmin = INF;
	for (int ral = 0; ral < n; ral++) {
		if (d[ral][0] == d[ral][1] and d[ral][2] == d[ral][3] and d[ral][2] == d[ral][4] and d[ral][0] == d[ral][2] and d[ral][0] != INF) {
			dmin = min(dmin, max_d[ral]);
		}
		else continue;
	}
	return dmin;
}

void read() {
	int x, y, w;
	cin >> n >> m;
	adj.assign(n, vector<pii>());
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		x--, y--; // TODO IMP
		adj[x].push_back(pii(y, w));
		adj[y].push_back(pii(x, w));
	}
	return;
}

int main () {
	int tst, ans, cnt = 1;
	cin >> tst;
	while (tst--) {
		read();
		floyd();
		ans = solve();
		if (ans == INF)
			ans = -1;
		cout << "Map " << cnt << ": " << ans << "\n";
		cnt++;
	}
	return 0;
}
