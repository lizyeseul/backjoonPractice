#include<stdio.h>
#include<string.h>

int main() {
	int t, r[1001];
	char s[1001][21];
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &r[i]);
		scanf("%s", &s[i]);
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < strlen(s[i]); j++) {
			for (int k = 0; k < r[i]; k++) {
				printf("%c", s[i][j], s[i][j], s[i][j]);
			}
		}
		if (i != t-1) {
			printf("\n");
		}
	}
	return 0;
}