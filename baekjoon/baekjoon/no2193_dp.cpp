#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	long long cur=1, pre=1, temp;
	if (n == 1) {
		printf("%d", pre);
	}
	else if (n == 2) {
		printf("%d", cur);
	}
	else {
		for (int i = 3; i < n; i++) {
			temp = cur + pre;
			pre = cur;
			cur = temp;
		}
		printf("%lld", cur + pre);
	}
	return 0;
}