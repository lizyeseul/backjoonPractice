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
	int n = 10;
	sort(v.begin(), v.end());

	int *cycle = new int[n + 1];
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
	}
	return 0;
}