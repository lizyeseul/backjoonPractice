#include<stdio.h>
#include<string.h>
int max(int a, int b) { return (a > b) ? a : b; }
int main() {
	char s1[1001], s2[1001];
	scanf("%s", &s1);
	scanf("%s", &s2);
	int lcs[1002][1002] = { 0, };
	for (int i = 1; i <= strlen(s2); i++) {
		for (int j = 1; j <= strlen(s1); j++) {
			if (s2[i - 1] == s1[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}
	printf("%d", lcs[strlen(s2)][strlen(s1)]);
	return 0;
}