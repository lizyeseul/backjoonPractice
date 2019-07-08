#include<stdio.h>
#include<string.h>
int main() {
	char str[1000001];
	scanf("%[^\n]", &str);
	int count = 0, flag=0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 32) {
			if (i == 0 || i == strlen(str) - 1) {
				if (str[1] == 0) {
					flag = 1;
				}
				continue;
			}
			count++;
		}
	}
	if (flag == 1) {
		printf("0");
	}
	else {
		printf("%d", count + 1);
	}
}