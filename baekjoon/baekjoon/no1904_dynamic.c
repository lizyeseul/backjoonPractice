#include<stdio.h>
int main() {
	//1 2 3 5 8 13
	int n;
	int ans;
	int a = 1, b = 2;
	scanf("%d", &n);
	if (n > 2) {
		for (int i = 3; i <= n; i++) {
			int temp = a;
			a = b;
			b = temp + b;
			if (a > 15746) {
				a %= 15746;
				b %= 15746;
			}
		}
		ans = b % 15746;
	}
	else if (n == 1) {
		ans = 1;
	}
	else if (n == 2) {
		ans = 2;
	}
	printf("%d", ans);
	
	return 0;
}