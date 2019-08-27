#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int ori = n;
	int a, b;
	int count = 0;

	if (n < 10) {
		a = 0;
		b = n;
	}
	else {
		a = n / 10;
		b = n % 10;
	}

	int plus = a+b;
	int New = b * 10 + (plus % 10);
	count++;

	while (New != ori) {
		n = New;
		if (n < 10) {
			a = 0;
			b = n;
		}
		else {
			a = n / 10;
			b = n % 10;
		}

		plus = a + b;
		New = b * 10 + (plus % 10);
		count++;
	}
	printf("%d", count);

	return 0;
}