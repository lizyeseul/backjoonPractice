#include<stdio.h>
#include<algorithm>
using namespace std;
int **forest;
int **memo;
int maxRoot=0;

bool isIn(int x, int y, int n) {
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}

int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int dfs(int x, int y, int n) {
	if (memo[x][y] != -1) {
		return memo[x][y];
	}
	int nextX, nextY;
	int count=1;
	bool canGo = false;
	for (int k = 0; k < 4; k++) {
		nextX = x + direction[k][0];
		nextY = y + direction[k][1];

		if (isIn(nextX, nextY, n) == true) {
			if (forest[nextX][nextY] > forest[x][y]) {
				canGo = true;
				int temp = dfs(nextX, nextY, n);
				if (temp > count) {
					count = temp;
				}
			}
		}
	}
	if (memo[x][y] > maxRoot) {
		maxRoot = memo[x][y];
	}
	if (canGo == false) {
		return memo[x][y]=1;
	}
	else {
		return memo[x][y] = count + 1;
	}
}
int main() {
	int n, b;
	scanf("%d", &n);
	forest = new int*[n];
	memo = new int*[n];
	for (int i = 0; i < n; i++) {
		forest[i] = new int[n];
		memo[i] = new int[n];
		fill(memo[i], memo[i] + n, -1);

		for (int j = 0; j < n; j++) {
			scanf("%d", &b);
			forest[i][j] = b;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memo[i][j] = dfs(i, j, n);
		}
	}
	printf("%d", maxRoot);

	return 0;
}