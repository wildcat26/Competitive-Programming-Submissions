#include <bits/stdc++.h>
using namespace std;

int n;
int coord[200][2]; // coords
vector <vector <long> > d;

int calDist(int x1, int y1, int x2, int y2) {
	return int(0.5 + 1000 * sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

void floyd() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d[i][j] = calDist(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
			d[j][i] = d[i][j]; // k = 0 step done, by setting weights
		}
		d[i][i] = 0;
	}
	long temp;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp = max(d[i][k], d[k][j]);
				d[i][j] = min(d[i][j], temp);
			}
		}
	}
	return;
}

void read() {
	// n already read
	d.assign(n, vector <long>(n, 0));
	for (int i = 0; i < n; i++)
		cin >> coord[i][0] >> coord[i][1];
	floyd();
	return;
}

int main () {
	int tst = 0;
	while (cin >> n) {
		if (n == 0) 
			break;
		read();
		tst++;
		cout << "Scenario #" << tst << "\n"; 
		cout << fixed; // << showpoint;
		cout << setprecision(3);
		cout << "Frog Distance = " << float(d[0][1])/1000 << "\n\n"; 
	}
	return 0;
}
