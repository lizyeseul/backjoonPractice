#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int t, n;
	scanf("%d", &t);
	int arr[2][100000];
	int dp[2][3];
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[0][i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[1][i]);
		}

		if (n >= 1) {
			dp[0][0] = arr[0][0];
			dp[1][0] = arr[1][0];
		}
		if (n >= 2) {
			dp[0][1] = dp[1][0] + arr[0][1];
			dp[1][1] = dp[0][0] + arr[1][1];
		}
		if (n >= 3) {
			for (int i = 2; i < n; i++) {
				dp[0][2] = max(dp[1][1] , max(dp[0][0], dp[1][0]) ) + arr[0][i];
				dp[1][2] = max(dp[0][1], max(dp[0][0], dp[1][0])) + arr[1][i];

				dp[0][0] = dp[0][1];
				dp[0][1] = dp[0][2];
				dp[1][0] = dp[1][1];
				dp[1][1] = dp[1][2];
			}
		}
		printf("%d\n", max(dp[0][2], dp[1][2]));
	}
	return 0;
}