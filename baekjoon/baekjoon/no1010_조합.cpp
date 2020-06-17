#include<stdio.h>
int main() {
	int t;
	long long a, b, res;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &b, &a);
		res = 1;
		for (int i = 1; i <= b; ++i)
		{
			res = (res * (a - i + 1)) / i;
		}
		printf("%lld\n", res);
	}
	return 0;
}