#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	string *arr = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	string result = "";
	int atgc[4] = { 0, };
	char atoc[4] = { 'A','C','G','T' };
	int index = 0;
	int total = 0;
	for (int i = 0; i < m; i++) {
		fill(atgc,atgc+4, 0);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (arr[j][i] == atoc[k]) {
					atgc[k]++;
				}
			}
		}
		index = 0;
		for (int j = 1; j < 4; j++) {
			index = atgc[index] < atgc[j] ? j : index;
		}
		result += atoc[index];
		for (int j = 0; j < 4; j++) {
			total += index != j ? atgc[j] : 0;
		}
	}
	cout << result<<" "<<total;
	return 0;
}