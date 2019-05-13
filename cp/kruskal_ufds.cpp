#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct edge {
	int u, v, w;
};

bool Compare(const edge& e1, const edge& e2) {
	return e1.w < e2.w;
}

int n, m;
vector <vector <pii> > adj;
vector <edge> Edges;

vector <int> Rank, parent;

int find_set(int u) {
	while (u != parent[u])
		u = parent[u];
	return u;
}

void make_set() {
	for (int i = 0; i < n; i++) {
		parent[i] = i; // parent is itself
		Rank[i] = 0;
	}
	return;
}

void merge_set(int u, int v) {
	int root_u = find_set(u);
	int root_v = find_set(v);
	
	if (root_u == root_v)
		return;
	if (Rank[u] > Rank[v]) 			// u is in a taller tree
		parent[root_v] = root_u;
	else if (Rank[v] > Rank[u])		// v is in a taller tree
		parent[root_u] = root_v;
	else {// same rank, merge in any way, remember to increase rank of new root!
		parent[root_v] = root_u;
		Rank[u]++;
	}
	return;
}

void kruskal() {
	parent.assign(n, 0);
	Rank.assign(n, 0);
	
	make_set();
	
	vector <edge> mst;
	int ecount = 0, u, v, wt, total_wt = 0;
	sort(Edges.begin(), Edges.end(), Compare);
	for (int i = 0; i < m; i++) {
		u = Edges[i].u;
		v = Edges[i].v;
		wt = Edges[i].w;
		if (find_set(u) != find_set(v)) {
			mst.push_back({u, v, wt});
			merge_set(u, v);
			total_wt += wt;
			ecount++;
		}
		if (ecount == n - 1)
			break;
	}
	cout << total_wt << "\n";
	for (auto ee : mst)
		cout << 1 + ee.u << " " << 1 + ee.v << " " << ee.w << "\n";
	return;
}

void read() {
	cin >> n >> m;
	int x, y, w;
	adj.assign(n, vector<pii>());
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		x--; y--; // IMP TODO
		adj[x].push_back(pii(y, w));
		adj[y].push_back(pii(x, w));
		Edges.push_back({x, y, w});
	}
	return;	
}

int main () {
	read();
	kruskal();
	return 0;
}
