#include<iostream>
#include<algorithm>
using namespace std;

struct co {
	int x; int y;
	bool check;
};
co con[53];
co destination;

bool dfs(int n, int cur);
int distance(int ax, int ay, int bx, int by);
bool compare(co a, co b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}
int main() {
	int t, n;
	cin >> t;
	for(int k=0; k<t; k++) {
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			co temp;
			cin >> temp.x >> temp.y;
			temp.check = false;
			if (i == 0) {
				temp.check = true;
				con[i] = temp;
			}
			else if (i == n + 1) {
				destination = temp;
			}
			else {
				con[i] = temp;
			}
		}

		//sort(con, con+n+1, compare);

		bool result = dfs(n, 0);
		if (result == true) {
			cout << "happy" << endl;
		} else {
			cout << "sad" << endl;
		}
	}
	return 0;
}
bool dfs(int n, int cur) {
	if (distance(con[cur].x, con[cur].y, destination.x, destination.y) <= 1000){
		return true;
	}
	for (int c = 0; c <= n; c++) {
		if (distance(con[cur].x, con[cur].y, con[c].x, con[c].y) <= 1000 && con[c].check == false) {
			con[c].check = true;
			if (dfs(n, c) == true) {
				return true;
			}
		}
	}
	return false;
}
int distance(int ax, int ay, int bx, int by) {
	int dx = ax - bx;
	int dy = ay - by;
	if (dx < 0)	dx *= -1;
	if (dy < 0)	dy *= -1;
	return dx+dy;
}