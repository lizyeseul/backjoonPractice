#include<stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int main() {
	int n;
	scanf("%d", &n);
	int tri[500][500] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= i; k++) {
			scanf("%d", &tri[i][k]);
		}
	}

	int total[500][500] = { 0, };
	total[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		for (int k = 0; k <= i; k++) {
			if (k == 0) {
				total[i][k] = tri[i][k] + total[i - 1][k];
			}
			else {
				total[i][k] = tri[i][k] + max(total[i - 1][k], total[i - 1][k - 1]);
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (total[n - 1][i] > max) {
			max = total[n - 1][i];
		}
	}
	printf("%d", max);
	return 0;
}