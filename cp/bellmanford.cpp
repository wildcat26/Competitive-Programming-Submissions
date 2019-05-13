#include <bits/stdc++.h>
using namespace std;
const long INFI = (long)1e12;

int n, m;
vector <long> d;
vector <int> pred;
bool flag;

class edge {
	int u, v, cost;
	public:	
		edge(int u, int v, int cost) {
			this->u = u;
			this->v = v;
			this->cost = cost;
		}
		bool relax();
		int getVertex() {
			return v;
		}
};

bool edge::relax()  {
	if (d[u] == INFI)
		return false;
	if (d[v] > d[u] + cost) {
		d[v] = d[u] + cost;
		pred[v] = u;
		return true;
	}
	return false;
}

vector <edge> e;

void read() {
	int x, y, w;
	cin >> n >> m;
	d.assign(n, INFI);
	pred.assign(n, -1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		e.push_back(edge(x - 1, y - 1, w));
	}
	return;
}

void bellmanFord(int src) {
	d[src] = 0;
	bool ans;
	for (int i = 0; i < n - 1; i++) {
		flag = false;
		for (int j = 0; j < m; j++) {
			ans = e[j].relax();
			if (ans == true)
				flag = true;
		}
		if (flag == false)
			break;
	}
	return;
}

vector<int> negCycle() {
	// after having run bellmanFord (n - 1) times
	bool ans;
	int x = -1; // last vertex that was relaxed in nth phase
	int y = -1; // earliest vertex from source that was relaxed in nth phase?
	// y lies in neg wt cycle, as #pred from x to src can be atmost n, thus we can reach in cycle in less than n step, once in cycle, we'll be stuck in the cycle
	for (int j = 0; j < m; j++) {
		ans = e[j].relax();
		if (ans == true)
			x = e[j].getVertex();
	}
	vector <int> neg;
	if (x == -1)
		return neg; // no neg cycle
	// reaches here if x got relaxed
	cout << "\nx = " << x << "\n";
	y = x; 
	for (int i = 0; i < n; i++)
		y = pred[y];
	// to go back n times from x, will reach a vertex in neg cycle
	for (int curr = y; ; curr = pred[curr]) {
		if (curr == y && neg.size() > 1)
			break;
		neg.push_back(curr);
		// y added only once
	}
	cout << "\ny = " << y << "\n";
	reverse(neg.begin(), neg.end());
	return neg;
}

int main () {
	read();
	bellmanFord(0);
	for (int i = 0; i < n; i++)
		cout << d[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << pred[i] << " ";
	vector <int> ncyc = negCycle();
	cout << "\n";
	for (auto v : ncyc)
		cout << v << " ";
	return 0;
}
