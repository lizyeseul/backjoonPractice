#include<stdio.h>
int main() {
	int t;
	long long n, r, res;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &r, &n);
		res = 1;
		for (int i = 1; i <= r; ++i)
			res = (res * (n - i + 1)) / i;
		printf("%lld\n", res);
	}
	return 0;
}