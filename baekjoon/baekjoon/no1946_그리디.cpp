#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int main() {
	int t,n;
	scanf("%d", &t);
	vector<pair<int, int> > v;
	int a, b;
	int min;
	int count;
	while (t--) {
		v.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a,&b);
			v.push_back(make_pair(a, b));
		}

		sort(v.begin(), v.end(),compare);
		count = 1;
		min = v[0].second;
		for (int i = 1; i < n; i++) {
			if (v[i].second < min) {
				min = v[i].second;
				count++;
			}
		}
		printf("%d ", count);
	}
	return 0;
}