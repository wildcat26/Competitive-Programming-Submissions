#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> adj;
vector <int> deg;
vector <int> parent;

int bfs(int u, int f) {
  parent[u] = u;
  queue <int> q;
  q.push(u);
  while (!q.empty()) {
  	int x = q.front();
  	q.pop();
  	for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++) {
  		if (parent[*it] == -1) { // unvisited
  			if (*it == f) {
  				parent[*it] = x;
  				return 0;
  			}
  			else if (deg[*it] >= 4) {
  				q.push(*it);
  				parent[*it] = x;
  			}
  		}
  	}
  }
 return -1;
}

int deg_check(int n, int *x, int *y) {
 bool first = true;
 for (int i = 0; i < n; i++) {
 	if (deg[i] < 2)
 		return 0;
 	else if (deg[i] % 2 == 1 && first == true)
 		*x = i, first = false;
 	else if (deg[i] % 2 == 1 && first == false)
 		*y = i;
 }
 if (first == true)
 	return 2; // indicating fully even; possible!
 else return 1;
}

int main () {
	int n, m, x, y, ans = 2;
	int u, v;
	scanf(" %d %d", &n, &m);
	do { 
	  ans = 2; 
	  adj.resize(n);
	  deg.resize(n);
	  parent.resize(n);
	  u = -1, v = -1;
	  for (int i = 0; i < n; i++) {
	  	parent[i] = -1;
	  	deg[i] = 0;
	  	adj[i].push_back(i);
	  }
	  for (int i = 0; i < m; i++) {
	  	scanf(" %d %d", &x, &y);
	  	adj[x - 1].push_back(y - 1);
	  	adj[y - 1].push_back(x - 1);
	  	deg[x - 1]++;
	  	deg[y - 1]++;
	  }

	  ans = deg_check(n, &u, &v);
	  if (ans == 0)
	  	printf("Poor Koorosh\n");
	  else if (ans == 2)
	  	printf("0\n");
	  else {
	  	ans = bfs(u, v);
	  	if (ans == -1)
	  		printf("Poor Koorosh\n");
	  	else {
	  		int ecount = 0;
	  		int curr = parent[v];
	  		while (curr != u) {
				ecount++;
				curr = parent[curr];
			}
	  		printf("%d\n", ecount + 1);
	    }
	  }
	  scanf(" %d %d", &n, &m);
	  adj.clear();
	  parent.clear();
	  deg.clear();
	} while (!(n == 0 && m == 0));
	 return 0;
}
