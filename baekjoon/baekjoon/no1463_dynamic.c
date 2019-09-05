#include<stdio.h>
int min(int a, int b) { return (a < b) ? a : b; }
int main() {
	int n;
	scanf("%d", &n);
	int* make = (int*)malloc(sizeof(int)*(n+1));
	if (n > 3) {
		make[0] = 0;
		make[1] = 0;
		make[2] = 1;
		make[3] = 1;

		for (int i = 4; i <= n; i++) {
			if (i % 3 == 0 && i % 2 == 0) {
				make[i] = 1 + min(min(make[i / 3], make[i / 2]), make[i - 1]);
			}
			else if (i % 3 == 0 && i % 2 != 0) {
				make[i] = 1 + min(make[i / 3], make[i - 1]);
			}
			else if (i % 3 != 0 && i % 2 == 0) {
				make[i] = 1 + min(make[i / 2], make[i - 1]);
			}
			else {
				make[i] = 1 + make[i - 1];
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			make[i] = 1;
		}
	}
		printf("%d\n", make[n]);
	return 0;
}