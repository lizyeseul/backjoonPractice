#include<stdio.h>
#include<math.h>
int isSosu(int s);
int main() {

	int t, result[10000];
	int sosu[50001];
	scanf("%d", &t);

	for (int i = 1; i <= 50000; i++) {
		sosu[i] = isSosu(i);
	}

	for (int i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);

		for (int k = 2; k <= n / 2; k++) {
			if (sosu[k] == 1 && sosu[n - k] == 1) {
				result[i * 2-1] = k;
				result[i * 2] = n - k;
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		printf("%d %d\n", result[i * 2 - 1], result[i * 2]);
	}
	
	return 0;
}
int isSosu(int s) {
	if (s == 2)
		return 1;
	else if (s == 1 || s % 2 == 0)
		return 0;
	for (int temp = 2; temp <= sqrt(s); temp++) {
		if (s%temp == 0) {
			return 0;
		}
	}
	return 1;
}