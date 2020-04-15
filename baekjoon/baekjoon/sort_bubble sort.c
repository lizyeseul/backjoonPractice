#include<stdio.h>

void main() {
	int max = 10;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };

	for (int i = 0; i < max-1; i++) {
		for (int j = i+1; j < max; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < max; i++) {
		printf("%d ", arr[i]);
	}

}