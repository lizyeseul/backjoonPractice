#include<stdio.h>
int isBig(int a, int b);
void swap(int a, int b);
int* x;
int* y;
int main() {
	int n;
	scanf("%d", &n);
	 x = (int*)malloc(sizeof(int)*n);
	 y = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}

	for (int i = 0; i < n-1; i++) {
		for (int k = i + 1; k < n; k++) {
			if (isBig(i, k) == 1) {
				swap(i, k);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d %d\n",x[i], y[i]);
	}
	return 0;
}

void swap(int a, int b) {
	int temp = x[a];
	x[a] = x[b];
	x[b] = temp;
	temp = y[a];
	y[a] = y[b];
	y[b] = temp;
}