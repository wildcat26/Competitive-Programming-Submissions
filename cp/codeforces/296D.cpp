#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
int n;
vector <vector <int> > edge;
vector <vector <int> > d;
vector <int> order;
unsigned long long int DD = 0;
vector <long long> ans;

void floyd() {
	for (int i = 0; i < n; i++) // from front! of order[]
		for (int j = 0; j < n; j++)
			d[i][j] = edge[order[i]][order[j]];
	 // k = 0th phase
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
			}
		}
		DD = 0;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				DD += d[i][j];
			}
		}
		ans.push_back(DD);
	}
	return;
}

void read() {
	cin >> n;
	edge.assign(n, vector<int>(n, 0));
	d.assign(n, vector<int>(n, INF));
	order.assign(n, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> edge[i][j];
	for (int i = 0; i < n; i++) {
		cin >> order[i];
		order[i]--;
	}
	return;
}

int main() {
	read();
	reverse(order.begin(), order.end());
	floyd();
	reverse(ans.begin(), ans.end());
	for (auto v : ans)
		cout << v << " ";
	cout << "\n";
	return 0;
}
