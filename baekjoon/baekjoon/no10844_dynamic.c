#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	long long stair[100][10] = { 0, };
	if (n == 1) {
		printf("9");
	}
	else {
		for (int i = 0; i < 10; i++) {
			stair[0][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				if (j - 1 >= 0) {
					stair[i][j] += stair[i - 1][j - 1];
				}
				if (j + 1 < 10) {
					stair[i][j] += stair[i - 1][j + 1];
				}
				stair[i][j] %= 1000000000;
			}
		}
		long long total = 0;
		for (int i = 0; i < 10; i++) {
			total += stair[n][i];
		}
		printf("%d", total);
	}
	return 0;
}