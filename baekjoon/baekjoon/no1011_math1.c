#include<stdio.h>
int main() {
	int t, x[10000], y[10000], result[10000];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}

	for (int i = 0; i < t; i++) {
		int l = y[i] - x[i];
		int count=0, flag=0, re=0;
		for (int k = 1; k <= l; k++) {
			count++;
			if (flag == 0) {
				flag = 1;
				k += re;
			}
			else {
				flag = 0;
				k += re;
				re++;
			}
		}
		result[i] = count;
	}
	for (int i = 0; i < t; i++) {
		printf("%d", result[i]);
		if (i < t - 1)	printf("\n");
	}
	return 0;
}