#include <stdio.h>
int temp[5000000];

void quick(int arr[], int start, int end, int k);
int main() {

	int arr[5000000];
	
	int n, k;
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	quick(arr, 0, n-1, k-1);

	printf("%d", arr[k-1]);
	
	return 0;
}

void quick(int arr[], int start, int end, int k) {
	if (start >= end) {
		return;
	}

	int pivot = start;
	int left = start + 1;
	int right = end;

	int count = 0;
	while (left <= right && count < 20) {
		while (arr[pivot] > arr[left] && left < end) {
			left++;
			count++;
		}
		while (arr[pivot] < arr[right] && start < right) {
			right--;
			count++;
		}
		if (left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		} else {
			int temp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = temp;
		}
	}
	if (start <= k && k <= right - 1) {
		quick(arr, start, right - 1, k);
	}
	if (right + 1 <= k && k <= end) {
		quick(arr, right + 1, end, k);
	}
}