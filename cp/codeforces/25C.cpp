#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, k;
vector <vector<int> > d;

void process(int u, int v, int wt) {
	if (d[u][v] <= wt)
		return;
	int d1, d2; // IMP u --> v OR v --> u 
	d[u][v] = wt;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d1 = d[i][u] + wt + d[v][j];
			d2 = d[i][v] + wt + d[u][j];
			d1 = min(d2, d1);
			d[i][j] = min(d[i][j], d1);
			d[j][i] = d[i][j]; // IMP!
		}
	}
	return;
}

unsigned long long int calSum() {
	unsigned long long int dsum = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			dsum += d[i][j];
	return dsum;
}

void read() {
	cin >> n;
	int x, y, w;
	d.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> w;
		x--, y--; // IMP TODO
		process(x, y, w);
		cout << calSum() << " ";
	}
	return;
}

int main () {
	read();
	return 0;
}
