#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
class edge {
	public:
	vector <int> data;
		edge(int u = 0, int v = 0, int w = 0) { 	//int u, v, w;
			data.push_back(u);
			data.push_back(v);
			data.push_back(w);
		}
};

bool Compare1 (const edge& e1, const edge& e2) {
	return e1.data[2] < e2.data[2];
}
bool Compare2 (const edge& e1, const edge& e2) {
	return e1.data[3] < e2.data[3];
}

int n, m;
vector <edge> Edges;
vector <int> parent, Rank;

void make_set() {
	for (int i = 0; i < n; i++)
		parent[i] = i;
	return;
}

int find_set(int u) {
	while (u != parent[u])
		u = parent[u];
	return u;
}

void merge_set(int u, int v) {
	int root_u = find_set(u);
	int root_v = find_set(v);
	if (root_u == root_v)
		return;
	if (Rank[u] > Rank[v])
		parent[root_v] = root_u;
	else if (Rank[u] < Rank[v])
		parent[root_u] = root_v;
	else {
		parent[root_v] = root_u;
		Rank[u]++;
	}
	return;
}

/*
0 --- none
1 --- at least one
2 --- any
*/

void kruskal() {
	parent.assign(n, 0);
	Rank.assign(n, 0);
	make_set();
	sort(Edges.begin(), Edges.end(), Compare1);
	int nxt_w, u, v, w;
	for (int i = 0; i < m; ) {
		u = Edges[i].data[0];
		v = Edges[i].data[1];
		w = Edges[i].data[2];
		if (i != m - 1)
			nxt_w = Edges[i + 1].data[2];
		else nxt_w = INF;
		if (find_set(u) == find_set(v))
			Edges[i++].data.push_back(0); // none
		else if (nxt_w > w) {
			Edges[i++].data.push_back(2); // any
			merge_set(u, v);
		}
		else {
			int ptr2, ptr1 = i;
			int tu, tv;
			int stu, stv;
			ptr2 = ptr1 + 1;
			while (ptr2 < m) {
				if (Edges[ptr2].data[2] == Edges[ptr2 - 1].data[2])
					ptr2++;
				else break;
			}
			// now ptr1.w ---- (ptr2 - 1).w are same
			bool flag = false;
			for (int j = ptr1; j < ptr2; j++) {
				tu = Edges[j].data[0];
				tv = Edges[j].data[1];
				if (find_set(tu) == find_set(tv))
					Edges[j].data.push_back(0); // none
				else {
					flag = true;
					stu = tu;
					stv = tv;
					Edges[j].data.push_back(1); // at least one
				}
			}
			i = ptr2;
			if (flag)
				merge_set(stu, stv);
		}
		
	}
	sort(Edges.begin(), Edges.end(), Compare2);
	return;
}

void read() {
	int x, y, w;
	cin >> n >> m;
	Edges.assign(m, edge());
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		x--, y--; // IMP TODO
		Edges[i].data[0] = x;
		Edges[i].data[1] = y;
		Edges[i].data[2] = w;
		Edges[i].data.push_back(i); // to maintain order of input
	}
	return;
}

int main () {
	read();
	kruskal();
	cout << "\n";
	int val;
	for (int i = 0; i < m; i++) {
		//cout << Edges[i].data.size() << "\n";
		val = Edges[i].data[4];
		if (val == 0)
			cout << "none\n";
		else if (val == 1)
			cout << "at least one\n";
		else cout << "any\n";
	}
	return 0;
}
