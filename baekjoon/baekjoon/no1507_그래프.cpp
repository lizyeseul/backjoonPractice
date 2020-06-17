#include<stdio.h>
int main() {
	int n;
	int total = 0;
	scanf("%d", &n);
	int **cost = new int*[n];
	int **original = new int*[n];
	for (int i = 0; i < n; i++) {
		cost[i] = new int[n];
		original[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
			if(i >= j)
				total += cost[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i >= j) continue;
				if (i == k || j == k) continue;
				if (cost[i][k] == -1 || cost[k][j] == -1 || cost[i][j] == -1) continue;
				if (cost[i][k] + cost[k][j] == cost[i][j]) {
					total -= cost[i][j];
					cost[i][j] = -1;
					cost[j][i] = -1;
				}
				else if (cost[i][k] + cost[k][j] < cost[i][j] && cost[i][j] != -1) {
					printf("-1");
					return 0;
				}
			}
		}
	}

	printf("%d", total);
	
	return 0;
}