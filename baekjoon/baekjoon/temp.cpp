#include <iostream>

using namespace std;

int main()
{
	int arr[10] = { 5,2,7,6,8,9,1,3,10,4 };
	int n = 10;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}