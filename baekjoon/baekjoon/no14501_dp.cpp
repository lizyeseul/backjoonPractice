#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, t, p;
	scanf("%d", &n);
	
	int *price = new int[n];
	vector<vector<int> > v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		v[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &t, &p);
		price[i] = p;
		if (n >= i + t) {
			v[i + t - 1].push_back(i);
		}
	}

	int *dp = new int[n];
	dp[0] = v[0].empty() ? 0 : price[0];
	
	int maxDP, index, temp1;
	for (int i = 1; i < n; i++) {
		if (v[i].size() > 0) {
			maxDP = dp[i-1];
			for (int j = 0; j < v[i].size(); j++) {
				index = v[i][j];
				temp1 = price[index];
				temp1 += index > 0 ? dp[index - 1] : 0;
				maxDP = max(maxDP, temp1);
			}
			dp[i] = maxDP;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	printf("%d", dp[n - 1]);
	return 0;
}