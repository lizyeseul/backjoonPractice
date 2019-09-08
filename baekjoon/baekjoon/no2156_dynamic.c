#include<stdio.h>
int max2(int a, int b) { return (a > b) ? a : b; }
int max3(int a, int b, int c) { return (max2(a,b) > c) ? max2(a, b) : c; }
int main() {
	int n;
	int podo[10000] = { 0, }, total[10000] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &podo[i]);
	}
	total[0] = podo[0];
	total[1] = podo[0]+podo[1];
	total[2] = max3(podo[0] + podo[1], podo[0] + podo[2], podo[1] + podo[2]);
	for (int i = 3; i < n; i++) {
		total[i] = max3(total[i - 3] + podo[i - 1] + podo[i], total[i - 2] + podo[i], total[i - 1]);
	}
	printf("%d", total[n - 1]);
	return 0;
}