#include<stdio.h>
void main() {
	//a<b<c
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c) {
		int temp;
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c) {
		int temp;
		temp = c;
		c = b;
		b = temp;
	}

	char abc[3];
	scanf(" %c%c%c", &abc[0], &abc[1], &abc[2]);
	
	for (int i = 0; i < 3; i++) {
		if (abc[i] == 'A') {
			printf("%d ", a);
		} else if (abc[i] == 'B') {
			printf("%d ", b);
		} else if (abc[i] == 'C') {
			printf("%d ", c);
		}
	}
	return 0;
}