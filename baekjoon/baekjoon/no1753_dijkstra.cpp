#include<stdio.h>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

vector<pair<int,int> > a[20000];
int *d;
int INF = 300000;

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDis = distance + a[current][i].second;
			if (nextDis < d[next]) {
				d[next] = nextDis;
				pq.push(make_pair(next, -nextDis));
			}
		}
	}
}
int main() {
	int v, e;
	int startV;
	scanf("%d%d%d", &v, &e, &startV);
	a->resize(v);
	d = new int[v+1];

	for (int i = 1; i <= v; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < e; i++) {
		int start, end, c;
		scanf("%d%d%d", &start, &end, &c);
		a[start].push_back(make_pair(end, c));
	}

	dijkstra(startV);

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) {
			printf("INF ");
		}
		else {
			printf("%d ", d[i]);
		}
	}

	return 0;
}