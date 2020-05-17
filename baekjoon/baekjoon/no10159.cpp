#include<stdio.h>
int main() {
	int n,m;
	int x, y;
	scanf("%d%d", &n, &m);
	bool **arr = new bool*[n];
	int *result = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new bool[n];
		result[i] = n-1;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		if (arr[x - 1][y - 1] != true) {
			arr[x - 1][y - 1] = true;
			result[x - 1]--;
			result[y - 1]--;
		}
	}

	for (int i = 0; i < n; i++) {
		for (x = 0; x < n; x++) {
			for (y = 0; y < n; y++) {
				if (!(x == i) && !(y == i) && !(x == y)) {
					if (arr[x][i] == true && arr[i][y] == true && arr[x][y] != true) {
						arr[x][y] = true;
						result[x]--;
						result[y]--;
						printf("%d %d %d\n", x + 1, i + 1, y + 1);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}