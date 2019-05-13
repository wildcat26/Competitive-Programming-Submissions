#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
vector<int> visited;
vector<vector<int> > adjR;
vector<int> order; // INCREASING ORDER OF FINISH TIMES
int n;


void explore(int u) {
	visited[u] = 1;
	for (vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
		if (visited[*it] == 0)
			explore(*it);
	}
	order.push_back(u);
	return;
}

void dfs() {
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0)
			explore(i);
	}
	return;
}

void explore1(int u) {
	visited[u] = 1;
	//printf(" %d ", u);
	for (vector<int>::iterator it = adjR[u].begin(); it != adjR[u].end(); it++) {
		if (visited[*it] == 0)
			explore1(*it);
	}
	return;
}

int dfs1() {
	int cc = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (visited[order[i]] == 0) {
			cc++;
			explore1(order[i]);			
			printf("cc = %d\n", cc);
		}
	}
	return cc;
}

int main () {
	int grp, t;
	scanf(" %d", &t);
	char arr[100][100];
	while (t--) {
		scanf(" %d", &n);
		adj.assign(n, {});
		adjR.assign(n, {});
		visited.assign(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %c", &arr[i][j]);
				if (arr[i][j] == 'Y')
					adj[i].push_back(j);
					adjR[j].push_back(i);
			}
		}
		dfs();
		visited.assign(n, 0);
		grp = dfs1();
		printf("%d\n", grp);
		adj.clear();
		visited.clear();
		order.clear();
		adjR.clear();
	}
	return 0;
}
