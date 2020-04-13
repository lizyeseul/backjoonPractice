#include<stdio.h>

void main() {
	int max = 10;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };

	for (int i = 0; i < max; i++) {
		int min = 99;
		int index = i;
		for (int j = i; j < max; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	for (int i = 0; i < max; i++) {
		printf("%d ", arr[i]);
	}

}