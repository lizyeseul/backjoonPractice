#include <stdio.h>
void quicksort(int arr[], int start, int end);
int main() {
	int arr[10] = { 3,7,8,1,5,9,6,10,2,4 };
	quicksort(arr, 0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
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
	quicksort(arr, r+1, end);
}