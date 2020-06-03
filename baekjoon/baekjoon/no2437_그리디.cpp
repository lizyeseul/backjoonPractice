#include<stdio.h>
#include<algorithm>
int main() {
	int n;
	scanf("%d", &n);
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	std::sort(arr, arr + n);
	int total = 1;
	for (int i = 0; i < n; i++) {
		if (total < arr[i]) {
			printf("%d", total);
			return 0;
		}
		total += arr[i];
	}
	printf("%d", total);
	return 0;
}