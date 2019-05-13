#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
using pii = pair <int, int>;

int n, m, q;
vector <vector <pii> > adj;
vector <int> d;
vector <int> visited;

// Compare returns true when e1 is to be found before e2
struct edge {
	int u, v, w;
};

bool Compare(const edge& e1, const edge& e2) {
		if (e1.u != e2.u)	
			return e1.u < e2.u;
		else if (e1.v != e2.v)
			return e1.v < e2.v;
		else return e1.w <= e2.w;
}

void dijkstra(int src) {
	d.assign(n, INF);
	visited.assign(n, false);
	d[src] = 0;
	priority_queue <pii, vector<pii>, greater<pii> > q;
	q.push(pii(0, src));
	pii curr;
	int u, v, w;
	while (!q.empty()) {
		curr = q.top();
		q.pop();
		u = curr.second;
		
		if (visited[u])
			continue;
		visited[u] = true;
		for (auto pp : adj[u]) {
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

void calMax() {
	int dmax = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] != INF)
			dmax = max(dmax, d[i]);
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == dmax)
			cnt++;
	}
	cout << dmax << " " << cnt << "\n";
	return;
}

	
void read() {
	int x, y, wt;
	while (cin >> n >> m >> q) {
		adj.assign(n, vector <pii>());

		int k = 0;
		edge arr[m];
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> wt;
			if (x == y)
				continue;
			arr[k].u = min(x, y);
			arr[k].v = max(x, y);
			arr[k++].w = wt;
		}
		// sort
		sort(arr, arr + k, Compare);
		edge e;
		int u, v, w;
		for (int i = 0; i < k; ) {
			e = arr[i];
			u = e.u;
			v = e.v;
			w = e.w;
			adj[u].push_back(pii(v, w));
			adj[v].push_back(pii(u, w));
			while (u == arr[i].u and v == arr[i].v)
				i++;
		}
		int init;
		while (q--) {
			cin >> init;
			dijkstra(init);
			calMax();
		}
	}
	return;
}

int main () {
	read();
	return 0;
}

