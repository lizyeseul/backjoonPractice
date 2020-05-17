#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define max 32001

int n, inDegree[max];
vector<int> a[max];

void toSort() {
	int result[max];
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int  y = a[x][i];

			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}
int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int s,b;
		scanf("%d%d", &s, &b);
		a[s].push_back(b);
		inDegree[b]++;
	}
	toSort();
}