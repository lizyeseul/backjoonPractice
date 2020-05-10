#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;

	int* arr = new int[n];
	int* temp = new int[n];
	int num;
	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cin >> num;
			arr[i] = num;
		}
		else {
			for (int j = 0; j <= i; j++) {
				cin >> num;
				if (j == 0) {
					temp[j] = arr[0];
				}
				else if (j == i) {
					temp[j] = arr[j - 1];
				}
				else {
					temp[j] = max(arr[j - 1], arr[j]);
				}
				temp[j] += num;

				if (i == n - 1 && maxNum < temp[j]) {
					maxNum = temp[j];
				}
			}
			copy(temp, temp+i+1, arr);
		}
	}
	cout << maxNum;
	return 0;
}