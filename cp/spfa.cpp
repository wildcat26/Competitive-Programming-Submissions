#include <bits/stdc++.h>
using namespace std;
const long INFI = (long)1e12;
/* Queue of vertices that were relaxed but could not relax their neighbours */
/* Create a count array to count #relaxations of each vertex */
/* Don't enqueue a vertex if its already there in the queue */

int n, m;
vector <vector <pair<int,int> > > adj; // dealing with vertices, not edges, thus adj list better
vector <int> pred;
vector <long> d;
vector <int> cnt;
vector <bool> inQ;

void read() {
	cin >> n >> m;
	adj.assign(n, vector <pair<int, int> >());
	d.assign(n, INFI);
	pred.assign(n, -1);
	cnt.assign(n, 0);
	inQ.assign(n, false);
	int x, y, w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		adj[x - 1].push_back(pair<int, int>(y - 1, w));
		//adj[y - 1].push_back(pair<int, int>(x - 1, w));
	}
	return;
}

bool spfa(int src) {
	d[src] = 0;
	queue <int> q;
	q.push(src);
	int u, v, w;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		inQ[u] = false;
		for (auto pp : adj[u]) {
			v = pp.first;
			w = pp.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pred[v] = u;
				cnt[v]++;
				if (inQ[v] == false) {
					q.push(v);
					inQ[v] = true;
				} // else already in queue
			}
			if (cnt[v] > n) { // LOGIC SIMILAR TO BELLMAN FORD TO DETECT NEG WT CYCLE
				vector <int> neg;
				int x = -1, y = -1;
				x = v;
				y = x;
				for (int i = 0; i < n; i++)
					y = pred[y];
				cout << " x = " << x << " y = " << y << "\n";
				for (int curr = y; curr != -1; curr = pred[curr]) {
					if (curr == y && neg.size() > 1)
						break;
					cout << curr + 1<< " ";
					neg.push_back(curr);
				}
				cout << "\n";
				reverse(neg.begin(), neg.end());
				for (auto x : neg)
					cout << x + 1 << " ";
				cout << "\n";
				return false; // neg cycle
			}
		}
	}
	return true; // sp exists
}

int main () {
	read();
	cout << spfa(0) << " is the result\n";
	return 0;
}
