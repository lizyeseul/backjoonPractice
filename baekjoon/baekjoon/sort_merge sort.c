#include<stdio.h>
int num = 8;
int sorted[8];
int partition(int a[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		partition(a, start, middle);
		partition(a, middle + 1, end);
		merge(a, start, middle, end);
	}
	
}
int merge(int a[], int start, int middle, int end) {
	int i = start;
	int j = middle + 1;
	int k = start;

	while (i <= middle && j <= end) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else if (a[i] > a[j]) {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= end; t++) {
			sorted[k] = a[t];
			k++;
		}
	} else  {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = start; t <= end; t++) {
		a[t] = sorted[t];
	}
}
int main() {
	int arr[8] = { 3,2,5,8,4,1,6,7 };
	partition(arr, 0, num - 1);

	for (int l = 0; l < num; l++) {
		printf("%d ", arr[l]);
	}
	return 0;
}