#include<stdio.h>
int main() {
	int apart[15][15] = { 0, };
	int a, b, test;

	for (int i = 1; i <= 14; i++) {
		apart[0][i] = i;
	}

	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			if (j == 1) {
				apart[i][j] = 1;
			}
			else {
				apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
			}
		}
	}

	int result[10000] = { 0, };
	scanf("%d", &test);
	for (int k = 0; k < test; k++) {
		scanf("%d%d", &a, &b);
		result[k] = apart[a][b];
	}
	for (int k = 0; k < test; k++) {
		if (k == test - 1) {
			printf("%d", result[k]);
		}
		else {
			printf("%d\n", result[k]);
		}
	}
	return 0;
}