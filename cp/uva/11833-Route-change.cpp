#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
using pii = pair <int, int>;

int n, m, c, k;
vector <vector <pii> > adj;
vector <int> d;
vector <bool> visited;
vector <int> rem_dist;
vector <int> edges;

void dijkstra() {
	d.assign(n, INF);
	visited.assign(n, false);
	int u, v, w;
	//cout << k << "\n";	
	d[k] = 0;
	priority_queue <pii, vector<pii>, greater<pii> > q;
	q.push(pii(0, k));
	while (!q.empty()) {
		pii curr = q.top();
		q.pop();
		u = curr.second;
		visited[u] = true;
		//cerr << d[u] << "\n";
		if (u <= c - 1)
			continue;						
		//cerr << "u is " << u << " ";
		//cerr << adj.size() << '\n';
		//cerr << adj[u].size() << '\n';
		for (auto pp : adj[u]) {
			//cerr << "nug\n";
			v = pp.first;
			w = pp.second;
			if (visited[v] == true)
				continue;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(pii(d[v], v));
			}
		}
	}
	//cout << "dijk over\n";
	return;
}

int solve() {
	int mmin = d[c - 1];
	for (int i = c - 2; i >= 0; i--) {
		rem_dist[i] = rem_dist[1 + i] + edges[i];
		if (d[i] != INF) {
			d[i] += rem_dist[i];
			mmin = min(mmin, d[i]);
		}
	}
	return mmin;
}

void read() {
	int u, v, w;
	adj.assign(n, vector <pii> ());
	rem_dist.assign(c, 0);
	edges.assign(c, 0);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(pii(v, w));
		adj[v].push_back(pii(u, w));
		if (abs(u - v) == 1 and min(u, v) <= c - 2)
			edges[min(u, v)] = w;
	}
	return;
}

int main () {
	while (cin >> n >> m >> c >> k, (n || m || c || k)) {
		//cerr << "n is before " << n << '\n';
		//exit(0);
		read();
		dijkstra();
		cout << solve() << "\n";
		adj.clear();
		d.clear();
		visited.clear();
		rem_dist.clear();
		edges.clear();
	}
	return 0;
}
