#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int n, r;
int edge[50][50];
int d[50][50];

void floyd() {
	// initially d matrix is same as edge matrix, bcoz all e
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			d[i][j] = edge[i][j]; // k = 0 phase
		d[i][i] = 0; // extra caution!
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
		}
	}	
	return;
}

void read() {
	int tst, x, y, cnt = 1;
	unsigned long long int ssum = 0;
	cin >> tst;
	while (tst--) {
		ssum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> edge[i][j];
		floyd();
		cin >> r;
		for (int i = 0; i < r; i++) {
			cin >> x >> y;
			x--, y--; // IMP TODO
			ssum += d[x][y];
		}
		cout << "Case #" << cnt << ": " << ssum << "\n";
		cnt++;
	}
	return;
}

int main() {
	read();
	return 0;	
}

