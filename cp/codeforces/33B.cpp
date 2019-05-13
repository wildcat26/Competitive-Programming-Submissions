#include <bits/stdc++.h>
using namespace std;
using pii = pair <int, int>;

const int OFST = 97;
const int N = 26;
const int INF = (int)1e9;

string s, t;
int m;
vector <vector <pii> > adj;
vector <vector <int> > d;

void floyd() {
	d.assign(N, vector<int>(N, INF));
	int v, w;
	for (int u = 0; u < N; u++) {
		d[u][u] = 0;
		for (auto pp : adj[u]) {
			v = pp.first;
			w = pp.second;
			d[u][v] = min(d[u][v], w); // k = 0th phase
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (d[i][k] < INF and d[k][j] < INF)
					d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
			}				
		}
	}
	return;
}

pii newLetter(int x, int y) {
	int letter = -1, dmin = INF;
	for (int c = 0; c < N; c++) {
		if (d[x][c] == INF or d[y][c] == INF)
			continue;
		if (dmin > (d[x][c] + d[y][c])) {
			letter = c;
			dmin = (d[x][c] + d[y][c]);
		}
	}
	return pii(dmin, letter);
}

void solve() {
	int sp = 0;
	vector <char> newS;
	pii cur;
	for (int i = 0; i < s.length(); i++) { // s and t have the same length
		if (s[i] == t[i]) {
			newS.push_back(s[i]);
			continue;
		}
		cur = newLetter(int(s[i]) - OFST, int(t[i]) - OFST);
		if (cur.first == INF) { // not possible!
			cout << "-1\n";
			return;
		}
		sp += cur.first;
		newS.push_back(char(cur.second + OFST));
	}
	cout << sp << "\n";
	for (auto v : newS)
		cout << v;
	cout << "\n";
	return;
}

void read() {
	char x, y;
	int w;
	cin >> s >> t;
	cin >> m;
	adj.assign(N, vector<pii>());
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		adj[int(x) - OFST].push_back(pii(int(y) - OFST, w));
	}
	return;
}

int main () {
	read();
	if (s.length() != t.length())
		cout << "-1\n";
	else {
		floyd();
		solve();
	}
	return 0;
}
