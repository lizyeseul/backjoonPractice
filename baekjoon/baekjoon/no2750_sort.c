#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int sort[1000];
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		sort[i] = temp;
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (sort[i] > sort[j]) {
				int temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", sort[i]);
	}
	return 0;
}