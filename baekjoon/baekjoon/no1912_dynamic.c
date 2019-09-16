#include<stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int main() {
	int n;
	scanf("%d", &n);
	int* num = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	int* big = (int*)malloc(sizeof(int)*n);
	big[0] = num[0];
	int m = big[0];
	for (int i = 1; i < n; i++) {
		if (big[i - 1] < 0) {
			big[i] = num[i];
		}
		else { big[i] = big[i - 1] + num[i]; }
		if (big[i] > m) {
			m = big[i];
		}
	}
	printf("%d", m);
	return 0;
}