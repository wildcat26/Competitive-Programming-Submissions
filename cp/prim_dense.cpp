#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = (int)1e9;

int n, m;
vector <vector <pii> > adj;

struct edge {
	int to = -1, wt = INF;
};

void prim() {
	set <pii> mst;
	int total_wt = 0;
	vector <bool> selected(n, false);
	vector <edge> min_edges(n); // all wts = INF and to = -1 by default
	min_edges[0].wt = 0;
	int chosen;
	for (int i = 0; i < n; i++) { // select a vertex n times
		chosen = -1;
		for (int j = 0; j < n; j++) {
			if (!selected[j] and (chosen == -1 or min_edges[chosen].wt > min_edges[j].wt))
				chosen = j;
		}
		// 0th vertex chosen initially
		if (min_edges[chosen].wt == INF) {
			cout << "NO MST\n";
			return;
		}
		mst.insert(pii(chosen, min_edges[chosen].to));
		selected[chosen] = true;
		total_wt += min_edges[chosen].wt;
		
		// update min wt edge (to selected vertices) of not selected vertices 
		int v, w;
		for (auto pp : adj[chosen]) {
			v = pp.first;
			w = pp.second; // wt of edge btw chosen and v (chosen ---------- v)
			if (min_edges[v].wt > w)
				min_edges[v] = {chosen, w};
		}
	}
	for (auto s : mst) {
		if (s.first == -1 or s.second == -1)
			continue;
		cout << 1 + s.first << " " << 1 + s.second << "\n";
	}
	return;
}

void read() {
	cin >> n >> m;
	adj.assign(n, vector<pii>());
	int x, y, w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		x--; // IMP TODO
		y--; // IMP TODO
		adj[x].push_back(pii(y, w));
		adj[y].push_back(pii(x, w));
	}
	return;
}

int main () {
	read();
	prim();
	return 0;
}
