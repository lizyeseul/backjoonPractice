#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	int arr[10001] = { 0, };
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}