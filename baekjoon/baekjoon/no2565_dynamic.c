#include<stdio.h>
int main() {
	//8 2 9 1 4 6 7 10
	int n;
	scanf("%d", &n);
	int ab[500] = { 0, };
	int maxN = 0;
	for (int i = 0; i < n; i++) {
		int index, b;
		scanf("%d%d", &index, &b);
		ab[index] = b;
		if (index > maxN) {
			maxN = index;
		}
	}
	maxN += 1;

	int line[500] = { 0, };

	line[0] = 0;
	for (int i = 1; i < maxN; i++) {
		if (ab[i] == 0) {
			line[i] = 0;
			continue;
		}
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (ab[i] > ab[j]) {
				if (line[j] > max) {
					max = line[j];
				}
			}
		}
		line[i] = max + 1;
	}

	int max = 0;
	for (int i = 0; i < maxN; i++) {
		if (line[i] > max) {
			max = line[i];
		}
	}
	printf("%d", n-max);
	return 0;
}