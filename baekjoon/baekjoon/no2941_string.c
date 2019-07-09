#include<stdio.h>
#include<string.h>
int main() {
	char word[101];
	scanf("%s", &word);
	int count = 0;
	for (int i = 0; i < strlen(word); i++) {
		char c = word[i];
		if (c == '=' && (word[i - 1] == 'c' || word[i - 1] == 'z' || word[i - 1] == 's')) {
			if (word[i - 1] == 'z' &&word[i - 2] == 'd') {
				count--;
			}
			continue;
		}
		else if (c == '-') {
			continue;
		}
		else if (c == 'j' && (word[i-1] == 'l' || word[i - 1] == 'n')) {
			continue;
		}
		else {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}