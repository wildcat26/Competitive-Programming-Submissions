#include <bits/stdc++.h>
using namespace std;
using pii = pair <int, int>;
const int INF = (int)1e9;

int n, m;
vector <vector <pii> > adj;
vector <vector <int> > d;
vector <vector <int> > pred; // last iteration at which shortest path got updated 

void floyd() {
	for (int i = 0; i < n; i++)
		d[i][i] = 0;
	for (int e = 0; e < n; e++) {
		for (auto pp : adj[e]) {
			d[e][pp.first] = pp.second;
			pred[e][pp.first] = 0;
		}
	}
	int temp;
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp = max(-INF, d[i][k] + d[k][j]);
				if (d[i][k - 1] < INF and d[k - 1][j] < INF) {	
					if (d[i][j] > temp) // sp improved in this phase!
						pred[i][j] = k - 1;
					d[i][j] = min(d[i][j], temp);
				}
			}
		}
	}
	return;
}

vector <int> seq;

void path(int src, int dest) {
	if (!pred[src][dest]) {
		seq.push_back(src + 1);
		return;
	}
	path(pred[src][dest], dest);
	path(src, pred[src][dest]);
	return;
}
// seq contains path from src to dest in reverse order (dest not included)

void read() {
	cin >> n >> m;
	int x, y, w;
	adj.assign(n, vector <pii>());
	d.assign(n, vector<int>(n, INF));
	pred.assign(n, vector<int>(n, -1));
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		x--;
		y--;
		adj[x].push_back(pii(y, w));
//		adj[y].push_back(pii(x, w));
	}
	return;
}

int main () {
	read();
	floyd();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << d[i][j] << " ";
		cout << "\n";
	}
	int a, b;
	cout << "preds\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << pred[i][j] << " ";
		cout << "\n";
	}
	
	cin >> a >> b;
//	cerr << "err" << "\n";
	//cout << a << b;
	path(--a, --b);
	for (auto u : seq)
		cout << u << " ";
	return 0;
}
