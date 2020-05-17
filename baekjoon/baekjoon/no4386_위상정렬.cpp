#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct star {
	float x, y;
};
star s[101];

class Edge {
public:
	int left, right;
	float distance;
	Edge(int a, int b) {
		this->left = a;
		this->right = b;
		this->distance = sqrt(pow(s[a].x - s[b].x, 2) + pow(s[a].y - s[b].y, 2));
	}
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};
vector<Edge> v;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%f%f", &s[i].x, &s[i].y);
		for (int k = 1; k < i; k++) {
			v.push_back(Edge(i,k));
		}
	}
	sort(v.begin(), v.end());



	int cycle[101];
	float total = 0;
	for (int i = 1; i <= n; i++) {
		cycle[i] = i;
	}

	for (int i = 0; i < v.size(); i++) {
		int l = v[i].left, r = v[i].right;
		int cl = cycle[l], cr = cycle[r];
		if (cl != cr) {
			total += v[i].distance;
			if (cl < cr) {
				for (int k = 1; k <= n; k++) {
					if (cycle[k] == cr) {
						cycle[k] = cl;
					}
				}
			}
			else {
				for (int k = 1; k <= n; k++) {
					if (cycle[k] == cl) {
						cycle[k] = cr;
					}
				}
			}
		}
	}
	printf("%f", total);
	return 0;
}
