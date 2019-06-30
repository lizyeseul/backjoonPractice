#include<stdio.h>
#include<string.h>

int main() {
	char word[100];
	int alpha[26];
	for (int i = 0; i < 26; i++) {
		alpha[i] = -1;
	}
	scanf("%s", word);
	int length = strlen(word);
	for (int i = 0; i < length; i++) {
		if (alpha[word[i] - 97] == -1) {
			alpha[word[i] - 97] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (i == 26) {
			printf("%d", alpha[i]);
		}
		else {
			printf("%d ", alpha[i]);
		}
	}
	return 0;
}