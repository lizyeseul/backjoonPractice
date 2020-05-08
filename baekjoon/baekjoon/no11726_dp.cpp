#include<iostream>
int arr[1001] = { 0, };
int dp(int n) {
	if (arr[n] == 0) {
		arr[n] = (dp(n - 1) + dp(n - 2)) % 10007;
	}
	return arr[n];
}
int main() {
	int n;
	arr[1] = 1;
	arr[2] = 2;
	std::cin >> n;
	std::cout << dp(n);
	return 0;
}