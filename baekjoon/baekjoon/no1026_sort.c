#include<stdio.h>
void main() {
	int n;
	scanf("%d", &n);
	int a[50], b[50];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	int index[50];
	for (int i = 0; i < n; i++) {
		int count = 0;//b
		for (int j = 0; j < n; j++) {
			//b
			if (b[i] > b[j] && i != j) {
				count++;
			}

			//a
			if (a[i] > a[j] && j > i) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		index[i] = count;
	}

	//2 4 5 3 1
	//1 3 4 2 0

	//0 1 1 1 6
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += a[n - 1 - index[i]] * b[i];
	}
	printf("%d", total);
}