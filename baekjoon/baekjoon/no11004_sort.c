#include <stdio.h>
int temp[5000];
int arr[5000] = { 0, };
void partition(int arr[], int start, int end, int k);
void merge(int arr[], int start, int middle, int end);
int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	partition(arr, 0, n - 1, k);
	
	printf("%d", arr[k-1]);
	
	return 0;
}
void partition(int arr[], int start, int end, int k) {
	if (start >= end) {
		return;
	}
	int middle = (start + end) / 2;
	partition(arr, start, middle,k);
	partition(arr, middle + 1, end,k);
	merge(arr, start, middle, end);
}
void merge(int arr[], int start, int middle, int end) {
	int left = start;
	int right = middle+1;
	int index = start;
	while (index <= end) {
		if (left <= middle && right <= end) {
			if (arr[left] < arr[right]) {
				temp[index] = arr[left];
				left++;
			}
			else {
				temp[index] = arr[right];
				right++;
			}
		}
		else if (left <= middle && right > end) {
			temp[index] = arr[left];
			left++;
		}
		else if (left > middle && right <= end) {
			temp[index] = arr[right];
			right++;
		}
		index++;
	}
	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}
}