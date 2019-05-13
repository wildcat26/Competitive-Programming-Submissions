#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m;
vector <vector <pii> > adj;

struct edge {
	int u, v, w;
};

bool Compare (const edge& e1, const edge& e2) {
	return e1.w < e2.w;
}

vector <edge> Edges;

void kruskal() {
	vector <int> tree_id(n);
	int x = 0, total_wt = 0;
	for (int i = 0; i < n; i++)
		tree_id[i] = i;
	vector <edge> mst;
	int u, v, ecount = 0;
	sort(Edges.begin(), Edges.end(), Compare);
	for (int i = 0; i < m; i++) {
		u = Edges[i].u;
		v = Edges[i].v;
		cout << "vertices " << u + 1 << " " << 1 + v << "\n";
		cout << "TRee ids -> " << tree_id[u] << " " << tree_id[v] << "\n";
		if (tree_id[u] == tree_id[v])
			continue;
		// give v's subtree the ID of u's subtree
		mst.push_back({u, v, Edges[i].w});
		total_wt += Edges[i].w;
		ecount++;
		if (ecount == n - 1) {
			cout << "breaking\n";
			break;
		}
		//cout << "here!\n";
		for (int i = 0; i < n; i++) {
			if (i == v);
			else if (tree_id[i] == tree_id[v])
				tree_id[i] = tree_id[u];
		}
		tree_id[v] = tree_id[u];
		cout << "\n";
	}	
	//cout << mst.size();
	for (auto ee : mst)
		cout << ee.u + 1 << " " << ee.v + 1 << " " << ee.w << "\n"; 
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
	cout << "here\n";
	kruskal();
	return 0;
}
