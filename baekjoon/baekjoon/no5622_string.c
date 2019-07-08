#include<stdio.h>
#include<string.h>
int main() {
	char word[16];
	int count = 0;
	scanf("%s", &word);
	for (int i = 0; i < strlen(word); i++) {
		char c = word[i] - 59;
		if (c == 31) {
			c -= 2;
		}else if (c > 22) {
			c -= 1;
		}
		count += c / 3 + 1;
	}
	printf("%d", count);
	return 0;
}