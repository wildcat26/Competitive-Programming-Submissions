#include <bits/stdc++.h>
using namespace std;
const long long INFI = (long long)1e12;

int n, m;
vector <vector< pair <int, int> > > adj;
vector <long long> d;
vector <int> pred;
vector <bool> visited;

void dijkstra(int src) {
	using pll = pair<long long, int>;
	priority_queue <pll, vector<pll>, greater<pll> > q;
	q.push({0, src});
	while (!q.empty()) {
		pll p = q.top();
		q.pop();
		int u = p.second;
		visited[u] = true;
		d[u] = p.first;
		for (auto pp : adj[u]) {
			int v = pp.first;
			int w = pp.second;
			if (visited[v] == true)
				continue;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pred[v] = u;
				q.push(pll(d[v], v));
			}
		}
	}
	return;
}

void read() {
	int u, v, w;
	scanf(" %d %d", &n, &m);
	adj.assign(n, vector < pair <int, int> > ());
	d.assign(n, INFI);
	pred.assign(n, int(-1));
	visited.assign(n, false);
	for (int i = 0; i < m; i++) {
		scanf(" %d %d %d", &u, &v, &w);
		adj[u - 1].push_back({v - 1, w});
		adj[v - 1].push_back({u - 1, w});
	}
	return;
}

int main () {
	read();
	dijkstra(0);
	if (d[n - 1] == INFI) {
		cout << "-1\n";
		return 0;
	}
	vector <int> path;
	for (int v = n - 1; v != 0; v = pred[v])
		path.push_back(v);
	path.push_back(0);
	reverse(path.begin(), path.end());
	for (auto v : path)
		cout << 1 + v << " ";
	cout << "\n";	
	return 0;
}
