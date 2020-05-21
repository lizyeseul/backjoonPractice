#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int dp[3];
	int cur, pre;
	if (n >= 1) {
		scanf("%d", &cur);
		dp[0] = cur;
		if (n == 1) {
			printf("%d", dp[0]);
			return 0;
		}
	}
	if (n >= 2) {
		pre = cur;
		scanf("%d", &cur);
		dp[1] = cur + pre;
		if (n == 2) {
			printf("%d", dp[1]);
			return 0;
		}
	}
	if (n >= 3) {
		pre = cur;
		scanf("%d", &cur);
		dp[2] = max(dp[1], max(cur + pre, dp[0] + cur));
	}
	
	for (int i = 4; i <= n; i++) {
		pre = cur;
		scanf("%d", &cur);
		int m = max(dp[2], max(dp[1] + cur, dp[0] + pre + cur));
		dp[0] = dp[1];
		dp[1] = dp[2];
		dp[2]=m;
	}
	printf("%d", dp[2]);
	return 0;
}