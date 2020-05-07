#include<iostream>
using namespace std;
int* arr;
int dp(int n) {
	if (arr[n] != 0) {
		return arr[n];
	}
	else {
		arr[n] = (dp(n - 1) + dp(n - 2)) % 15746;
		return arr[n];
	}
}
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1";
	}
	else if (n == 2) {
		cout << "2";
	}
	else if(n>=3){
		arr = new int[n + 1]{ 0, };
		arr[1] = 1;
		arr[2] = 2;
		cout << dp(n);
	}
	return 0;
}