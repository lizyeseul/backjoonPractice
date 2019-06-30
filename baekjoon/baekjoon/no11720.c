#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int total;
	char string[100];
	scanf("%d", &total);
	scanf("%s", string);
	int result=0;
	for (int i = 0; i < total; i++) {
		result += string[i] - 48;
	}
	printf("%d", result);
	return 0;
}