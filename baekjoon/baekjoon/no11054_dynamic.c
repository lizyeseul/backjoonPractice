#include<stdio.h>
int main() {
	int n;
	int seq[1000];
	int orm[1000] = { 0, };
	int nearim[1000] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	orm[0] = 1;
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (seq[i] > seq[j]) {
				if (orm[j] > max) {
					max = orm[j];
				}
			}
		}
		orm[i] = max + 1;
	}

	nearim[n-1] = 1;
	for (int i = n-2; i >= 0; i--) {
		int min = 0;
		for (int j = n-1; j > i; j--) {
			if (seq[i] > seq[j]) {
				if (nearim[j] > min) {
					min = nearim[j];
				}
			}
		}
		nearim[i] = min + 1;
	}
	
	int total = 0;
	for (int i = 0; i < n; i++) {
		int sum = orm[i] + nearim[i];
		if (sum > total) {
			total = sum;
		}
	}
	printf("%d", total -1);
	return 0;
}