#include<iostream>
using namespace std;

struct co {
	int x; int y;
	bool check;
};
co con[53];
co destination;

bool dfs(int n, int cur);
int distance(co a, co b);

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
	if (distance(con[cur], destination) <= 1000){
		return true;
	}
	else {
		for (int c = 0; c <= n; c++) {
			if (distance(con[cur], con[c]) <= 1000 && con[c].check == false) {
				con[c].check = true;

				bool result = dfs(n, c);
				if (result == true) {
					return true;
				}

				con[c].check = false;
			}
		}
		return false;
	}
}
int distance(co a, co b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	if (dx < 0)	dx *= -1;
	if (dy < 0)	dy *= -1;
	return dx+dy;
}