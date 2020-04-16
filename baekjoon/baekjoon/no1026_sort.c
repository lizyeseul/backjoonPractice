#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a[50], b[50];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	int index[50] = { 0, };
	int indexNum = -1;
	for (int i = 0; i < n; i++) {
		int min = 9999;
		for (int j = 0; j < n; j++) {
			//b
			if (b[j] < min && index[j] == 0) {
				min = b[j];
				indexNum = j;
			}

			//a
			if (a[i] > a[j] && j > i) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		index[indexNum] = i+1;
	}
	
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += a[n - index[i]] * b[i];
	}
	printf("%d", total);
	return 0;
}