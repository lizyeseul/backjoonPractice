#include<stdio.h>
#include<string.h>
int main() {
	int N, count=0;
	char word[101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", word);
		if (isGroup(word) == 1) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
int isGroup(char w[101]) {
	char alpha[26] = { 0, };
	for (int k = 0; k < strlen(w); k++) {
		int index = w[k] - 97;
		if (alpha[index] == 1 && w[k-1] != w[k]) {
			return 0;
		}
		alpha[index] = 1;
	}
	return 1;
}