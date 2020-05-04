#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n != 0) {
		long long total = 1;
		for (int i = n+1; i <= 2*n; i++) {
			total *= i;
			int j = i - n;
			total /= j;
		}
		total /= n+1;
		cout << total << endl;
		cin >> n;
	}
	return 0;
}