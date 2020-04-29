#include<stdio.h>
int swap(int* a, int*b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b) {
		swqp(a, b);
	}
	if (a > c) {
		swqp(a, c);
	}
	if (b > c) {
		swqp(c, b);
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