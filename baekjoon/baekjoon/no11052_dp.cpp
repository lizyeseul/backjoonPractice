#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int n, p;
	scanf("%d", &n);

	int *card = new int[n+1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p);
		card[i] = p;
	}

	
	int *dp = new int[n+1];
	int total = 0;

	dp[1] = card[1];
	int m;
	for (int i = 2; i <= n; i++) {
		m = card[i];
		for (int k = i - 1; k >= (i / 2); k--) {
			if (m < dp[k] + dp[i - k]) {
				m = dp[k] + dp[i - k];
			}
		}
		dp[i] = m;
	}
	printf("%d", dp[n]);
	return 0;
}