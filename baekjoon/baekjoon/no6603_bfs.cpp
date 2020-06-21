#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v;
vector<int> lotto;
void printV() {
	for (int l = 0; l < v.size(); l++) {
		printf("%d -> ", v[l]);
	}
	printf("\n\n");
}
void printL() {
	for (int l = 0; l < lotto.size(); l++) {
		printf("%d -> ", lotto[l]);
	}
	printf("\n\n");
}
void dfs(int num) {
	if (num == v.size() - 1 && lotto.size() <= 5) {
		return;
	}
	//printf("num : %d\n", num);
	if (lotto.size() == 6) {
		for (int l = 0; l < lotto.size(); l++) {
			printf("%d ", lotto[l]);
		}
		printf("\n");
		return;
	}

	for (int idx = num + 1; idx < v.size(); idx++) {
		//printf("idx : %d\n", idx);
		lotto.push_back(v[idx]);
		dfs(idx);
		lotto.pop_back();
	}
}
int main() {
	int k,n;
	scanf("%d", &k);
	while (k != 0) {
		v.clear();
		lotto.clear();
		for (int i = 0; i <k; i++) {
			scanf("%d", &n);
			v.push_back(n);
		}
		for (int i = 0; i < v.size(); i++) {
			lotto.push_back(v[i]);
			dfs(i);
			lotto.pop_back();
		}
		printf("\n");
		scanf("%d", &k);
	}
	return 0;
}
// 7 1 2 3 4 5 6 7 0