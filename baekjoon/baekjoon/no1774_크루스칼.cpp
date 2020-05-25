#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class God {
public:
	int x, y;
	God(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
vector<God> g;
vector<God> aisle;

class Edge {
public:
	int left, right;
	double distance;
	Edge(int left, int right) {
		double d = pow(g[left].x - g[right].x,2);
		d += pow(g[left].y - g[right].y, 2);
		this->distance = sqrt(d);
		this->left = left;
		this->right = right;
	}
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
	bool operator ==(const God &god) {
		bool temp = (this->left == god.x && this->right == god.y);
		bool temp2 = (this->left == god.y && this->right == god.x);
		return temp || temp2;
	}
};
vector<Edge> v;

int getParent(int set[], int x) {
	if (set[x] == x) {
		return x;
	}
	else {
		return set[x] = getParent(set, set[x]);
	}
}
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a < b) {
		set[b] = a;
	}
	else {
		set[a] = b;
	}
}
bool find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g.push_back(God(x-1, y-1));
		for (int j = 0; j < i; j++) {
			v.push_back(Edge(j, i));
		}
	}
	vector<Edge>::iterator it;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		aisle.push_back(God(x - 1, y - 1));
		it = find(v.begin(), v.end(), God(x - 1, y - 1));
		if (it != v.end()) {
			(*it).distance = 0;
		}
	}
	
	sort(v.begin(), v.end());

	int *cycle = new int[n];
	for (int i = 0; i < n; i++) {
		cycle[i] = i;
	}

	double total = 0;
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(cycle, v[i].left, v[i].right)) {
			total += v[i].distance;
			count++;
			if (count == n - 1) {
				break;
			}
			unionParent(cycle, v[i].left, v[i].right);
		}
	}
	printf("%.2lf", total);
	return 0;
}