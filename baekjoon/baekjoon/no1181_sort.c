#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int search(int n, char word[][51], char a[]) {
	for (int k = 0; k <= n; k++) {
		if (strcmp(word[k], a) == 0) {
			return 0;
		}
	}
	return 1;
}
int compare(char a[50], char b[50]) {
	if (strlen(a) < strlen(b)) {
		return 0;//a가 앞순서
	}
	else if (strlen(a) > strlen(b)) {
		return 1;//b가 앞순서
	}
	else if (strlen(a) == strlen(b)) {
		int length = strlen(a);
		int index = 0;
		while (length > 0) {
			if (a[index] < b[index]) {
				return 0;
			}
			else if (a[index] > b[index]) {
				return 1;
			}
			length--;
			index++;
		}
	}
	return 2;//같음
}

int main() {
	int n;
	scanf("%d", &n);
	char word[20000][51];
	char temp[51];
	int count=0;
	for (int i = 0; i < n; i++) {
		scanf("%s", &temp);
		if (search(i, word, temp) == 1) {
			strcpy(word[count], temp);
			count++;
		}
	}
	n = count;
	
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (compare(word[i], word[j]) == 1) {
				strcpy(temp, word[i]);
				strcpy(word[i], word[j]);
				strcpy(word[j], temp);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s", word[i]);
	}
	
	return 0;
}

