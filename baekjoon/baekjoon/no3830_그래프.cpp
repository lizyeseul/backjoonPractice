#include<stdio.h>
#include<algorithm>
using namespace std;

int getParent(int cost[], int set[], int a) {//find
	if (set[a] == a) {
		return a;
	}
	else {
		int temp = getParent(cost, set, set[a]);
		cost[a] += cost[set[a]];
		return set[a] = temp;
	}
}
void unionParent(int cost[], int set[], int a, int b, int w) {//union
	int ap = getParent(cost, set, a);
	int bp = getParent(cost, set, b);

	if (ap < bp) {
		cost[bp] -= cost[b] - cost[a] - w;
		set[bp] = ap;
	}
	else {
		cost[ap] += cost[b] - cost[a] - w;
		set[ap] = bp;
	}
}
bool isSameParent(int cost[], int set[], int a, int b) {//makeset
	int ap = getParent(cost, set, a);
	int bp = getParent(cost, set, b);
	if (ap == bp) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int n, m;
	while (true) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) {
			return 0;
		}

		int *check = new int[n+1];
		for (int i = 0; i <= n; i++) {
			check[i] = i;
		}
		int *cost = new int[n + 1];
		fill(cost, cost + n + 1, 0);


		char work;
		int a, b, w;
		while (m--) {
			work = getchar();
			work = getchar();
			if (work == '!') {
				scanf("%d%d%d", &a, &b, &w);
				if (isSameParent(cost, check, a, b) == false) {
					unionParent(cost, check, a, b, w);
				}
			}
			else if (work == '?') {
				scanf("%d%d", &a, &b);
				if (isSameParent(cost, check, a, b) == true) {
					getParent(cost, check, a);
					getParent(cost, check, b);
					printf("%d\n", cost[b] - cost[a]);
				}
				else {
					printf("UNKNOWN\n");
				}
			}
		}
	}
	return 0;
}