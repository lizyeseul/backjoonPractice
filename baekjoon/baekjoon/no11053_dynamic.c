#include<stdio.h>
int main() {
	int n;
	int seq[1000];
	int flag[1000] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	flag[0] = 1;
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (seq[i] > seq[j]) {
				if (flag[j] > max) {
					max = flag[j];
				}
			}
		}
		flag[i] = max + 1;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (flag[i] > max) {
			max = flag[i];
		}
	}
	printf("%d", max);
	return 0;
}