#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = (long)1e9;

int n;
vector <vector <pii> > adj;
vector <int> d;
vector <bool> visited;

void dijkstra(int src) { // 0th vertex is src
	d.assign(n, INF);
	visited.assign(n, false);
	d[src] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(pii(0, src));
	pii cur;
	int u, v, w;
	while (!q.empty()) {
		cur = q.top();
		q.pop();
		u = cur.second;
		if (visited[u])
			continue;
		visited[u] = true;
		d[u] = cur.first;
		for (auto pp: adj[u]) {
			v = pp.first;
			w = pp.second;
			if (visited[v])
				continue;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(pii(d[v], v));
			}
		}
	}
	return;
}

void solve() {
	dijkstra(0); // 1st processor
	int ans = -INF;
	for (int i = 0; i < n; i++) {
		ans = max(ans, d[i]);
	}
	cout << ans << "\n";	
	return;
}

void read() {
	adj.assign(n, vector<pii>()); // n already read
	char ch;
	int w;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (scanf(" %d", &w)) {
				adj[i].push_back(pii(j, w));
				adj[j].push_back(pii(i, w));
			}
			else scanf("%c", &ch);
		}
	}
	return;
}

int main() {
	while (cin >> n) {
		read();
		solve();
	}
	return 0;
}
