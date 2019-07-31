#include<stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	int h[1000] = { 0, }, w[1000] = { 0, }, n[1000] = { 0, };
	for (int i = 0; i < t; i++) {
		scanf("%d%d%d", &h[i], &w[i], &n[i]);
	}

	for (int i = 0; i < t; i++) {
		int H = n[i] % h[i];
		int W = n[i] / h[i] + 1;
		if (H == 0) {
			H = h[i];
			W -= 1;
		}
		printf("%d",H);
		if (W < 10)
			printf("0");
		printf("%d", W);
		if (i < t - 1) {
			printf("\n");
		}
	}
	return 0;
}