#include<stdio.h>

int main() {
	int T, result[10000] = { 0, };
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int m, n, x, y;
		int ans;
		scanf("%d%d%d%d", &m, &n, &x, &y);

		int last = gcd(m,n);
		result[i] = -1;
		int k = x;
		while (k < last) {
			if (k%n == y) {
				result[i] = k;
				break;
			}
			k += m;
		}

	}
	for (int i = 0; i < T; i++) {
		printf("%d", result[i]);
		if (i < T - 1) {
			printf("\n");
		}
	}
	return 0;
}
int gcd(int a, int b) {
	int A = a, B = b;
	while (B != 0) {
		int temp = A % B;
		A = B;
		B = temp;
	}
	return a * b / A;
}