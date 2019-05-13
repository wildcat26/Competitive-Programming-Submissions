#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
using pii = pair<int, int>;

int n, m;
vector < set <pii> > adj;
vector <int> d;
vector <bool> visited;
vector <int> pred;

void read() {
	adj.assign(n, set <pii>());
	d.assign(n, INF);
	
	return;
}

int main () {
	while (cin >> n >> m, n || m) {
		read();
	}
	return 0;
}

