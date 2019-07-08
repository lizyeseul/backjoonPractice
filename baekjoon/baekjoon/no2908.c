#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char a[4], b[4];
	scanf("%s%s", &a, &b);

	int A=0, B=0;
	for (int i = 2; i >= 0; i--) {
		A += a[i] - 48;
		B += b[i] - 48;
		if (i != 0) {
			A *= 10;
			B *= 10;
		}
	}
	if (A > B) {
		printf("%d", A);
	}
	else {
		printf("%d", B);
	}
	return 0;
}