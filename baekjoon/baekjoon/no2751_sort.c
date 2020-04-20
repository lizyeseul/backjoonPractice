#include<stdio.h>
void quicksort(int arr[], int start, int end);
int main() {
	int n;
	scanf("%d", &n);
	int arr[1000000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quicksort(&arr, 0, n-1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
void quicksort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}

	int pivot = start;
	int l = start + 1;
	int r = end;
	while (l <= r) {
		while (arr[l] <= arr[pivot] && l <= end) {
			l++;
		}
		while (arr[r] >= arr[pivot] && r > start) {
			r--;
		}
		if (l > r) {
			int temp = arr[r];
			arr[r] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}

	}
	quicksort(arr, start, r - 1);
	quicksort(arr, r + 1, end);
}