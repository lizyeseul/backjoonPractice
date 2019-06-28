#include<stdio.h>
int pi(int n);

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", pi(n));

	return 0;
}

int pi(int n) {
	if (n == 0) {
		return 0;
	}
	else if(n == 1) {
		return 1;
	}
	else {
		int a = 0, b = 1;
		for (int i = 1; i < n; i++) {
			int temp = a;
			a = b;
			b += temp;
		}
		return b;
	}
}