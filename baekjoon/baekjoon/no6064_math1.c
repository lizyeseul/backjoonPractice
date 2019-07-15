#include<stdio.h>
/*
15
40000 39999 39999 39998
40000 39999 40000 39999
40000 40000 40000 39999
40000 39998 40000 39997
39999 2 39998 2
3 40000 3 39999
40000 3 40000 3
8 2 4 2
10 12 2 12
12 10 12 10
12 10 1 1
12 6 12 6
10 1 5 1
1 10 1 5
1 1 1 1
*/
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
		if (k == 0) {
			k = m;
		}
		while (k <= last) {
			int kn = k % n;
			if (kn == 0) {
				kn = n;
			}
			//printf("k : %d kn:%d\n", k, kn);
			if (kn == y) {
				result[i] = k;
				break;
			}
			k += m;
		}
		//printf("result : %d\n\n", result[i]);
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
	//printf("최소공배수 : %d\n", a * b / A);
	return a * b / A;
}