#include<stdio.h>
long long int arr[1000001][2];
long long int dp(int n) {
	if (arr[n][0] == 0) {
		arr[n][0] = (2*dp(n-1) + 3* dp(n - 2) + arr[n - 3][1])%1000000007;
		arr[n][1] =( arr[n - 1][1] + arr[n][0] * 2) % 1000000007;
	}
	return arr[n][0];
}
int main() {
	int n;
	scanf("%d", &n);
	arr[0][0] = 1;
	arr[1][0] = 2;
	arr[2][0] = 7;
	arr[0][1] = 2* arr[0][0];
	arr[1][1] = 2 * arr[1][0]+ arr[0][1];
	arr[2][1] = 2 * arr[2][0]+ arr[1][1];
	printf("%lld", dp(n));
	return 0;
}