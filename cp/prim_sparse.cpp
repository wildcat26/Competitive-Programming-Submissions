#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = (int)1e9;

int n, m;
vector <vector <pii> > adj;

struct edge {
	int to = -1, wt = INF;
	bool operator < (const edge& e) const {
		return wt < e.wt;
	}
};

void prim() {
	int chosen, wt = 0, total_wt = 0;
	vector <edge> min_edges(n);
	min_edges[0].wt = 0;
	set <edge> q;
	q.insert({0, 0}); // 0th vertex inserted first
	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			cout << "NO MST\n";
			return;
		}
		chosen = q.begin()->to;
		wt = q.begin()->wt;
		q.erase(q.begin());
		total_wt += wt;
		//if (min_edges[chosen].wt == INF) // won't happen bcoz we aren't pushing such edges
		if (min_edges[chosen].to != -1)
			cout << chosen + 1 << " " << min_edges[chosen].to + 1 << "\n";
		// update min wt of not selected vertices
		int v, w;
		
		for (auto pp : adj[chosen]) {
			v = pp.first;
			w = pp.second;
			if (min_edges[v].wt > w) {
				q.erase({v, min_edges[v].wt});
				min_edges[v] = {chosen, w};
				q.insert({v, w});
			}
		}
	}
	cout << total_wt << "\n";
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
