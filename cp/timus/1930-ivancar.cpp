#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;

int n, m, src, dest;
vector <vector <int> > adjU;
vector <vector <int> > adjD;
vector <int> d;
vector <bool> visited[2];
vector <int> pred;
using pii = pair <int, int>;
using pipi = pair <int, pii>;
priority_queue <pii, vector <pipi>, greater<pipi> > q;

void relaxU(int u, int v, int gear) {
	int w = 0;
	if (gear == 1)
		w = 1;
	// final gear will be 0
	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		pred[v] = u;
		q.push(pipi(d[v], pii(v, 0)));
	}
	return;
}

void relaxD(int u, int v, int gear) {
	int w = 0;
	if (gear == 0)
		w = 1;
	// final gear will be 1
	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		pred[v] = u;
		q.push(pipi(d[v], pii(v, 1)));
	}
	return;
}

void dijkstra(int par) {
	d[src] = 0;
	int u, w, curr_par, d_u;
	q.push(pipi(0, pii(src, par)));
	while (!q.empty()) {
		pipi curr = q.top();
		q.pop();
		d_u = curr.first;
		pii x = curr.second;
		u = x.first;
		curr_par = x.second;
		for (auto v : adjU[u]) {
			relaxU(u, v, curr_par);
		}
		for (auto v : adjD[u]) {
			relaxD(u, v, curr_par);
		}
	}
	return;
}

void read() {
	int x, y;
	cin >> n >> m;
	adjU.assign(n, vector <int>());
	adjD.assign(n, vector <int>());
	d.assign(n, INF);
	pred.assign(n, -1);
	visited[0].assign(n, false);
	visited[1].assign(n, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adjU[x - 1].push_back(y - 1);
		adjD[y - 1].push_back(x - 1);	
	}
	cin >> src >> dest;
	src--, dest--;
	return;
}

int main () {
	read();
	int dd = 0;
	dijkstra(0);
	dd = d[dest];
	dijkstra(1);
	dd = min(dd, d[dest]);
	cout << dd << "\n";
	return 0;
}
