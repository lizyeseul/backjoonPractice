#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int findWall(int max);
int findSafe();
void spreadV(int x, int y);

int **map;
bool **copyMap;
int n, m;
struct co {
	int x, y;
};
queue<co> q;
queue<co> original;
stack<co> wall;

int main() {
	cin >> n >> m;

	map = new int*[n];
	copyMap = new bool*[n];

	int temp;
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		copyMap[i] = new bool[m];
		for (int j = 0; j < m; j++) {
			copyMap[i][j] = false;

			cin >> temp;
			map[i][j] = temp;
			if (temp == 2) {
				co V;
				V.x = i; V.y = j;
				original.push(V);
			}
		}
	}
	int max = findWall(0);
	cout << max << endl;

	return 0;
}
int findWall(int max) {
	if (wall.size() == 3) {
		int curMax = findSafe();
		if (curMax > max) {
			max = curMax;
		}
		return max;
	}

	co W;
	if (wall.size() == 0) {
		W.x = -1;
		W.y = -1;
	}
	else {
		W = wall.top();
	}
	
	co tempW;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (W.x < i || (W.x == i && W.y < j)) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					tempW.x = i; tempW.y = j;
					wall.push(tempW);

					max = findWall(max);

					map[i][j] = 0;
					wall.pop();
				}
			}
		}
	}
	return max;
}
int findSafe() {
	int result = 0;

	q = original;
	while (!q.empty()) {
		co curV = q.front();
		q.pop();
		spreadV(curV.x, curV.y);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				result++;
			}
			if (copyMap[i][j] == true) {
				map[i][j] = 0;
				copyMap[i][j] = false;
			}
		}
	}
	return result;
}
void spreadV(int x, int y) {
	if (x > 0) {
		if (map[x - 1][y] == 0) {
			map[x - 1][y] = 2;
			copyMap[x - 1][y] = true;
			co V;
			V.x = x - 1; V.y = y;
			q.push(V);
		}
	}
	if (x < n-1) {
		if (map[x + 1][y] == 0) {
			map[x + 1][y] = 2;
			copyMap[x + 1][y] = true;
			co V;
			V.x = x + 1; V.y = y;
			q.push(V);
		}
	}
	if (y > 0) {
		if (map[x][y-1] == 0) {
			map[x][y-1] = 2;
			copyMap[x][y-1] = true;
			co V;
			V.x = x; V.y = y-1;
			q.push(V);
		}
	}
	if (y < m-1) {
		if (map[x][y+1] == 0) {
			map[x][y+1] = 2;
			copyMap[x][y + 1] = true;
			co V;
			V.x = x; V.y = y+1;
			q.push(V);
		}
	}
}