#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pis = pair<int, string>;
using pli = pair<long, int>;

const long INFI = (long)1e12;
const int INF = (int)1e9;

struct edge {
	int u, v, w;
};

int n,m;
int src;

vector <vector <pii> > adj;
set <edge> Edges;
set <pii> pairs;

vector <long> d;
vector <bool> visited;

void dijkstra() {
	d.assign(n, INFI);
	visited.assign(n, false);
	d[src] = 0;
	priority_queue <pli, vector<pli>, greater<pli> > q;
	q.push(pli(0, src));
	pli cur;
	int u, v, w;
	while (!q.empty()) {
		cur = q.top();
		q.pop();
		u = cur.second;
		if (visited[u])
			continue;
		visited[u] = true;
		d[u] = cur.first;
		for (auto pp : adj[u]) {
			v = pp.first;
			w = pp.second;
			if (visited[v])
				continue;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(pli(d[v], v));
			}
		}
	}
	return;
}


void solve() {
	long dmax = -INFI;
	for (int i = 0; i < n; i++) {
		if (dmax < d[i])
			dmax = d[i];
	}
	if (dmax == INFI)
		cout << "Impossible\n";
	else cout << dmax << "\n"; 
}

void read() {
	string s;
	string s1, s2;
	int u, v, i, w;
	bool f1 = false, f2 = false;
	// n, m already read
	adj.assign(n, vector<pii>());
	vector <pis> names;
	for (int i = 0; i < n; i++) {
		cin >> s;
		names.push_back(pis(i, s));
	}
	for (int j = 0; j < m; j++) {
		cin >> s1 >> s2 >> w;
		
		for (auto pp : names) {
			i = pp.first;
			s = pp.second;
			
			if (s == s1) {
				u = i;
				f1 = true;
			}
			else if (s == s2) {
				v = i;
				f2 = true;
			}
			if (f1 and f2) {
				f1 = false;
				f2 = false;
				break;
			}
		}

		bool found = false;
		for (auto pp : adj[u]) {
			if (pp.first == v) {
				found = true;
				pp.second = max(pp.second, w);
			}
		}
		if (found) {
			for (auto pp : adj[v])
				if (pp.first == u)
					pp.second = max(pp.second, w);
		}
		else {
			adj[u].push_back(pii(v, w));
			adj[v].push_back(pii(u, w));				
		}
	}
	cin >> s1;
	for (auto pp : names) {
			i = pp.first;
			s = pp.second;
			
			if (s == s1) {
				src = i;
				break;
			}
	}
	return;
}

int main() {
	while (cin >> n >> m and (n || m)) {
		read();
		dijkstra();
		solve();
	}
	return 0;
}
