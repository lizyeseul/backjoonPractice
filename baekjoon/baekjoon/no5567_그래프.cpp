#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	int a, b;
	int total = 0;

	scanf("%d%d", &n, &m);
	vector<vector<int> > arr;
	vector<int> v;
	arr.resize(n + 1);
	bool *check = new bool[n + 1];

	for (int i = 0; i < n+1; i++) {
		arr[i] = v ;
	}
	fill(check, check + n + 1, false);
	check[1] = true;
	
	while (m--) {
		scanf("%d%d", &a, &b);
		if (a == 1) {
			if (check[b] == false) {
				v.push_back(b);
				check[b] = true;
				total++;
			}
		}
		else {
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
	}

	int index;
	for (int i = 0; i < v.size(); i++) {
		index = v[i];
		for (int j = 0; j < arr[index].size(); j++) {
			if (check[arr[index][j]] == false) {
				check[arr[index][j]] = true;
				total++;
			}
		}
	}

	
	printf("%d", total);

	return 0;
}