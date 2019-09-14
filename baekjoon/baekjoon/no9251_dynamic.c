#include<stdio.h>
#include<string.h>
int max(int a, int b) { return (a > b) ? a : b; }
int main() {
	char s1[1001], s2[1001];
	scanf("%s", &s1);
	scanf("%s", &s2);
	int lcs[1000][1000] = { 0, };

	for (int i = 0; i < strlen(s1); i++) {
		for (int j = 0; j < strlen(s2); j++) {
			if (i == 0 && j == 0) {
				lcs[0][0] = 0;
			}
			else if (i == 0 && j != 0) {
				lcs[i][j] = lcs[i][j - 1];
			}
			else if (i != 0 && j == 0) {
				lcs[i][j] = lcs[i - 1][j];
			}
			else {
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}

			if (s1[i] == s2[j]) {
				lcs[i][j]++;
			}
		}
	}

	printf("%d", lcs[strlen(s1) - 1][strlen(s2) - 1]);

	return 0;
}