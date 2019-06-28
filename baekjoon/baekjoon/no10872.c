#include<stdio.h>

int pac(int n);
int main() {
	int n;
	scanf("%d",&n);
	printf("%d", pac(n));
	return 0;
}

int pac(int n) {
	int total=1;
	for (int i = 2; i <= n; i++) {
		total *= i;
	}
	return total;
}