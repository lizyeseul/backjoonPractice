//1 1 1
//2 2 11 2
//3 4 111 21 12 3
//4 7 1111 22 211 121 112 31 13 
//5 13 11111 2111 1211 1121 1112 221 212 122 311 131 113 23 32

#include<stdio.h>
int main() {
	int dp[12];
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		printf("%d ", dp[n]);
	}
	return 0;
}