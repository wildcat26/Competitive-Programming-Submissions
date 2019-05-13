#include <bits/stdc++.h>
using namespace std;
char matrix[20][20];
int visited[20][20];
int m, n;
int di, dj;
int nbd[4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		if ((x + dx[i]) <= m - 1 && (x + dx[i]) >= 0 && (y + dy[i]) >= 0 && (y + dy[i]) <= n - 1 && matrix[x + dx[i]][y + dy[i]] == '.')
			nbd[i] = 1;
		else nbd[i] = 0;
	}
	return;
}

void dfs(int r, int c) {
	visited[r][c] = 1;
	if (r == di && c == dj)
		return;
	check(r, c);
	for (int i = 0; i < 4; i++)
		if (nbd[i] == 1)
			dfs(r + dx[i], c + dy[i]);
	return;
}

int main () {
	int t, fi, fj, si, sj;
	scanf(" %d", &t);
	bool first = false, sec = false, third = false;
	
	while (t--) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				visited[i][j] = 0;
		}
		scanf(" %d %d", &m, &n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%c", &matrix[i][j]);
				if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && matrix[i][j] == '.') {
					if (first == false) {
						fi = i, fj = j;
						first = true;
					}
					else if (sec == false) {
						sec = true;
						si = i, sj = j;
					}
					else {
						third = true;
						//printf("invalid\n");
						break;
					}
				}
			}
		}
		if (first == true && sec == true && third == false) {
			first = false;
			di = si;
			dj = sj;
			dfs(fi, fj);
			if (visited[di][dj] == 1)
				printf("valid\n");
			else printf("invalid_1\n");
		}
		else printf("invalid_2\n");
		first = false, sec = false, third = false;
	}
	return 0;
}
