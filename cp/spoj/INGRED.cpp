#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = (int)1e9;
int n, m;
int s;
int src[2];
vector <int> A[2];

vector <vector <pii> > adj;
vector <vector <int> > d;
int stores[8];

void floyd() {
	int v, w;
	d.assign(n, vector<int>(n, INF));
	for (int u = 0; u < n; u++) {
		d[u][u] = 0;
		for (auto pp : adj[u]) {
			v = pp.first;
			w = pp.second;
			d[u][v] = w; // k = 0th phase
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][k] == INF or d[k][j] == INF)
					continue;
				d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
			}
		}
	}
	return;
}

void getSet(int num) {
	A[0].clear();
	A[1].clear();
	for (int i = 0; i < s; i++) {
		if (num & (1 << i)) 	// if ith bit from left is on
			A[0].push_back(stores[i]);
		else A[1].push_back(stores[i]);	
	}
	return;
}

int dp(int par) {
	// breaking at u--v 
	int u, v, curr;;
	int sz = A[par].size();
	if (sz == 0)
		return 0;
	int c = 1;
	int temp[1 + sz];
	//cout << "\n" << src[par] << " ";
	temp[0] = src[par]; // starting from a source
	for (auto vv : A[par]){
	//	cout << vv << " ";
		temp[c++] = vv;
	}
	//cout << "\n";
	//cout << src[par] << " " << temp[1] << "\n";
	int loc, dsum = d[src[par]][temp[1]], ndsum; // d[src][temp[1]];
	for (int len = 2; len < sz + 1; len++) {
		curr = temp[len];
		ndsum = INF;
		for (int j = 0; j < len - 1; j++) {
			u = temp[j];
			v = temp[j + 1];
			if (ndsum > (dsum - d[u][v] + d[u][curr] + d[curr][v])) {
				ndsum = (dsum - d[u][v] + d[u][curr] + d[curr][v]);
				loc = j + 1; // where curr should be finally
			}
			// putting curr at the needed posn -- loc!
			
			//cout << "u = " << u << " v = " << v << " curr = " << curr << "\n";
			//cout << "dsum = " << dsum << "\n";
			//cout << "d[u][v] = " << d[u][v] << "\n";
			//cout << "d[u][curr] = " << d[u][curr] << "\n";
			//cout << "d[curr][v] = " << d[curr][v] << "\n";
			//cout << "ndsum " << ndsum << "\n";
			//cout << "--------------------------------------------------------\n";
		}
		if (ndsum > dsum + d[curr][temp[len - 1]]) {
			ndsum = (dsum + d[curr][temp[len - 1]]);
			loc = len;
		}
		for (int x = len; x > loc; x--)
				temp[x] = temp[x - 1];
			temp[loc] = curr;
		// NOT NEEDED ndsum = min(ndsum, dsum + d[temp[len]][curr]);
		dsum = ndsum;
		// handle i to len case separately!
	}
	return dsum;
}

void solve() {
	int s1, s2, dmin = INF;
	for (int i = 0; i < pow(2, s); i++) {
		getSet(i);
	//	cout << "set A[0] : \n";
	//	for (auto v : A[0])
	//		cout << v << " ";
	//	cout << "\n--------------------------------\n";
	//	cout << "set A[1] : \n";
	//	for (auto v : A[1])
	//		cout << v << " ";
	//	cout << "\n--------------------------------\n";
		s1 = dp(0);
		s2 = dp(1);
		//cout << i << " " << s1 << " " << s2 << "\n";
		dmin = min(dmin, s1 + s2);
	}	
	cout << dmin << "\n";
	return;
}

void read() {
	adj.assign(n, vector<pii>());	// n, m already read
	int x, y, w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w; // 0 INDEXED
		adj[x].push_back(pii(y, w));
		adj[y].push_back(pii(x, w));
	}
	cin >> s;
//	cout << s << "\n";
	for (int i = 0; i < s; i++)
		cin >> stores[i];
	cin >> src[0] >> src[1];
//	cout << src[0] << " " << src[1] << "\n";
	return;
}

int main () {
	while (cin >> n >> m) {
		read();
		floyd();
		solve();
	}
	return 0;
}
