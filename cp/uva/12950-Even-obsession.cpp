#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
using pii = pair <int, int>;

struct tup {
	int dist, v, st;
	inline bool operator > (const tup& tup1) const {
		return dist > tup1.dist;
	}
};

int n, m;
vector <vector <pii> > adj;
vector <int> d[2];
vector <bool> visited[2]; 

void dijkstra() {
 // 0 --> n - 1 shortest path
	d[0][0] = 0;
	int d_u, u, state, w, v;
	priority_queue <tup, vector <tup>, greater<tup> > q;
	q.push({0, 0, 0});
	while (!q.empty()) {
		tup curr = q.top();
		q.pop();
		d_u = curr.dist;
		u = curr.v;
		state = curr.st;
		for (auto pp : adj[u]) {
			v = pp.first;
			w = pp.second;
			if (d[(state + 1) % 2][v] > d[state][u] + w) {
				d[(state + 1) % 2][v] = d[state][u] + w;
				q.push({d[(state + 1) % 2][v], v, ((state + 1) % 2)});
			}
		}
	}
	return;
}

void read() {
	int x, y, w;
	adj.assign(n, vector <pii> ());
	d[0].assign(n, INF);
	d[1].assign(n, INF);
	visited[0].assign(n, false);
	visited[1].assign(n, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		adj[x - 1].push_back(pii(y - 1, w));
		adj[y - 1].push_back(pii(x - 1, w));
	}
	return;
}

int main () {
	while (cin >> n >> m) {
		read();
		dijkstra();
		if (d[0][n - 1] == INF)
			cout << "-1\n";
		else cout << d[0][n - 1] << "\n";
		adj.clear();
		d[0].clear();
		d[1].clear();
		visited[0].clear();
		visited[1].clear();
	}
	return 0;
}

