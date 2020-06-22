#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v;
vector<int> lotto;
// 7 1 2 3 4 5 6 7 0
void dfs(int num) {
	//printf("\n%d \n", num);
	lotto.push_back(v[num]);
	//for (int l = 0; l < lotto.size(); l++) printf("%d -> ", lotto[l]); printf("\n---------\n");
	if (num == v.size() -1 && lotto.size() <= 5) {
		lotto.pop_back();
		return;
	}
	if (lotto.size() == 6) {
		for (int l = 0; l < lotto.size(); l++) {
			printf("%d ", lotto[l]);
		}
		printf("\n");
		lotto.pop_back();
		return;
	}
	for (int idx = num + 1; idx < v.size(); idx++) {
		//printf("num %d, idx %d\n",num,idx);
		dfs(idx);
	}
	lotto.pop_back();
	return;
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
			dfs(i);
		}
		printf("\n");
		printf("--\n");
		scanf("%d", &k);
	}
	return 0;
}