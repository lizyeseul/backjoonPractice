#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Edge {
public:
	int left, right;
	int weight;
	Edge(int left, int right, int weight) {
		this->left = left;
		this->right = right;
		this->weight = weight;
	}
	bool operator <(Edge &edge) {
		return this->weight < edge.weight;
	}
};
vector<Edge> v;

int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a < b) set[b] = a;
	else set[a] = b;
}
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int l, r, w;
		scanf("%d%d%d", &l, &r, &w);
		v.push_back(Edge(l, r, w));
	}
	sort(v.begin(), v.end());

	int *cycle = new int[n+1];
	for (int i = 1; i <= n; i++) {
		cycle[i] = i;
	}

	int total = 0;
	int count = 0;
	for (int i = 0; i < v.size(); i++) {

		
		if (!find(cycle, v[i].left, v[i].right)) {
			total += v[i].weight;
			count++;
			if (count == n - 2) {
				break;
			}
			unionParent(cycle, v[i].left, v[i].right);
		}
		/*
		printf("%d %d, %d %d : %d\n", v[i].left, v[i].right, l, r,v[i].weight);
		total += v[i].weight;
		count++;
		

		if (l < r) {
			for (int i = 1; i <= n; i++) {
				if (cycle[i] == r) {
					cycle[i] = l;
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (cycle[i] == l) {
					cycle[i] = r;
				}
			}
		}*/
	}
	printf("%d", total);
	return 0;
}