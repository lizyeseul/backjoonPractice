#include<stdio.h>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int *coin = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	int total = 0;
	for (int i = n-1; i >= 0; i--) {
		total += k / coin[i];
		k -= k / coin[i] * coin[i];
	}
	printf("%d", total);
	return 0;
}