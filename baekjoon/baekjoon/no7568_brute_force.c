#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int x[50], y[50];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	int dungci[50] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int k = i; k < n; k++) {
			if (k == i)
				continue;
			if (x[i] > x[k] && y[i] > y[k]) {
				dungci[k]++;
			}
			else if (x[i] < x[k] && y[i] < y[k]) {
				dungci[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", dungci[i]+1);
	}
	return 0;
}