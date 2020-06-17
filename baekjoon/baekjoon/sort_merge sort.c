#include<stdio.h>
#define num 8
#define left pointer[0]
#define right pointer[1]
int sorted[num];
int partition2(int a[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		partition(a, start, middle);
		partition(a, middle + 1, end);
		merge(a, start, middle, end);
	}
	
}
/*
int merge2(int a[], int start, int middle, int end) {
	int left = start;
	int right = middle + 1;
	int cur = start;

	while (left <= middle && right <= end) {
		if (a[left] <= a[right]) {
			sorted[cur] = a[left];
			left++;
		}
		else if (a[left] > a[right]) {
			sorted[cur] = a[right];
			right++;
		}
		cur++;
	}
	if (left > middle) {
		for (right; right <= end; right++) {
			sorted[cur] = a[right];
			cur++;
		}
	} else  {
		for (left; left <= middle; left++) {
			sorted[cur] = a[left];
			cur++;
		}
	}
	for (cur = start; cur <= end; cur++) {
		a[cur] = sorted[cur];

	}
}*/

int partition(int a[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		partition(a, start, middle);
		partition(a, middle + 1, end);
		merge(a, start, middle, end);
	}
}
int merge(int a[], int start, int middle, int end) {
	int pointer[2] = { start, middle + 1 };
	int cur = start;

	while (left <= middle && right <= end) {
		if (a[left] < a[right]) {
			sorted[cur] = a[left];
			left++;
		}
		else {
			sorted[cur] = a[right];
			right++;
		}
		cur++;
	}

	int copy = left > middle ? right : left;
	for (copy; copy <= end; copy++, cur++) {
		sorted[cur] = a[copy];
	}
	for (cur = start; cur <= end; cur++) {
		a[cur] = sorted[cur];
	}
}
int main() {
	int arr[num] = { 3,2,5,8,4,1,6,7 };
	partition(arr, 0, num - 1);

	for (int l = 0; l < num; l++) {
		printf("%d ", arr[l]);
	}
	return 0;
}