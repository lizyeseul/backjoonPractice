#include<stdio.h>
#include<string.h>
int main() {
	char word[1000001], alpha[26] = { 0, };
	int max = 0, flag = 0, maxIndex = 0;
	scanf("%s", word);
	printf("%d\n", strlen(word));
	for (int i = 0; i < strlen(word); i++) {
		int index = word[i] - 97;
		if (word[i] > 95) {
			index = word[i] - 97;
		}
		else {
			index = word[i] - 65;
		}
		alpha[index]++;
		if (alpha[index] > max) {
			max = alpha[index];
			flag = 0;
			maxIndex = index;
		}
		else if (alpha[index] == max) {
			flag = 1;
		}
	}


	if (flag == 1) {
		printf("?");
	}
	else {
		printf("%c", maxIndex+65);
	}
	return 0;
}