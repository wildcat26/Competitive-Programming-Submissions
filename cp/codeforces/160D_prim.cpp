#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = (int)1e9;

struct edge {
	int to, wt;
	bool operator < (const edge& e) const {
		return wt < e.wt;
	}
};

int n, m;
vector <vector <pii> > adj;

void prim() {
	int chosen, v, w;
	set <edge> q;
	vector <edge> min_edges(n, {-1, INF});
	q.insert({0, 0});
	for (int i = 0; i < n; i++) {
		if (q.empty())
			break;
		auto it = q.begin();
		chosen = it->to;
		w = it->wt;
		q.erase(it);
		for (auto pp : adj[chosen]) {
			v = pp.first; 
			if (min_edges[v].wt > w) {
				q.erase({v, min_edges[v].wt});
				min_edges[v] = {chosen, w};
				q.insert({v, w});
			}
		}
	}
	return;
}

void read() {
	int x, y, w;
	cin >> n >> m;
	adj.assign(n, vector<pii>());
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		x--, y--; // IMP TODO
		adj[x].push_back(pii(y, w));
		adj[y].push_back(pii(x, w));
	}
	return;
}

int main () {
	return 0;
}
