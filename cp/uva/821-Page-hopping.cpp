#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;

int n = 100;
vector <vector <int> > adj;
vector <int> d;
int total = 0;

void bfs(int src) {
	d.assign(n, INF);
	d[src] = 0;
	queue <int> q;
	q.push(src);
	int u;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				total += d[v];
				q.push(v);
			}
		}
	}
	return;
}

int read() {
	int u, v, cnt = 1;
	set <int> vertex;
	adj.assign(n, vector<int>());
	while (cin >> u >> v) {
		if (u || v) {
			u--, v--; // TODO
			cnt++;
			adj[u].push_back(v);
			vertex.insert(u);
			vertex.insert(v);
		}
		else if (cnt == 1)
			exit(0);
		else break;
	}
	return vertex.size();
}

int main () {
	int tcnt = 1;
	int N, den;
	float ans = 0.0;
	cout << fixed << showpoint;
	cout << setprecision(3);
	while (1) {
		N = read();
		den = N * (N - 1);
		total = 0;
		for (int i = 0; i < n; i++)
			bfs(i);
		ans = float(total) / den;
		cout << "Case " << tcnt << ": average length between pages = " << ans << " clicks\n";
		tcnt++;
	}
	return 0;
}
