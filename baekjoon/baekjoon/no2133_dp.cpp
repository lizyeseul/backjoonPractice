#include<iostream>
int arr[31] = { 0, };
int dp(int n) {
	if (n % 2 != 0) {
		arr[n] = 0;
	}
	else if (arr[n] == 0) {
		arr[n] = 3 * dp(n - 2);
		for (int i = n - 4; i >= 0; i -= 2) {
			arr[n] += 2 * dp(i);
		}
	}
	return arr[n];
}
int main() {
	int n;
	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 3;
	std::cin >> n;
	std::cout << dp(n);
	return 0;
}