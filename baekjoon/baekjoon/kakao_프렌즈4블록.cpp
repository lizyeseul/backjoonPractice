#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int block[30][30];
//1:블록 있음 0:지울수 있는 블록 -1:블록없음

int same[4][2] = { {0,0},{1,0},{0,1},{1,1} };

int checkPang(int x, int y, vector<string> board) {
	int result = 0;
	if (block[x][y] == -1 || board[x][y] == 'x') return 0;

	if (board[x][y] == board[x + 1][y]
		&& board[x + 1][y] == board[x][y + 1]
		&& board[x][y + 1] == board[x + 1][y + 1]) {
		for (int k = 0; k < 4; k++) {
			if (block[x + same[k][0]][y + same[k][1]] != 0) {
				block[x + same[k][0]][y + same[k][1]] = 0;
				result++;
			}
		}
	}
	return result;
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	for (int i = 0; i < m; i++) {
		fill(block[i], block[i] + n, 1);
	}
	queue<int> none;
	while (true) {
		int change = 0;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				change += checkPang(i, j, board);
			}
		}
		if (change == 0) break;
		else answer += change;
		int ex = -1;
		for (int j = 0; j < n; j++) {
			for (int i = m - 1; i >= 0; i--) {
				if (block[i][j] == -1) {
					ex = i;
					break;
				}
				if (!none.empty() && block[i][j] == 1) ex = i;
				if (block[i][j] == 0) none.push(i);
				if (!none.empty() && ex != -1) {
					int pre = none.front();
					none.pop();
					board[pre].replace(j, 1, board[ex], j, 1);
					board[ex].replace(j, 1, "x");
					block[pre][j] = 1;
					block[ex][j] = 0;
					none.push(ex);
					ex = -1;
				}
			}
			while (!none.empty()) {
				block[none.front()][j] = -1;
				none.pop();
			}
			while (ex >= 0) {
				block[ex][j] = -1;
				ex--;
			}
		}
	}
	return answer;
}
int main() {
	vector<string> v;
	//v.push_back("TTTANT");
	//v.push_back("RRFACC");
	//v.push_back("RRRFCC");
	//v.push_back("TRRRAA");
	//v.push_back("TTMMMF");
	//v.push_back("TMMTTJ");
	//cout << solution(6, 6, v) << endl;//15

	//
	//v.clear();
	//v.push_back("CCBDE");
	//v.push_back("AAADE");
	//v.push_back("AAABF");
	//v.push_back("CCBBF");
	//cout << solution(4, 5, v) << endl;//14

	//v.clear();
	//v.push_back("AA");
	//v.push_back("AA");
	//cout << solution(2, 2, v) << endl;//4

	//v.clear();
	//v.push_back("AA");
	//v.push_back("AA");
	//v.push_back("AB");
	//cout << solution(3, 2, v) << endl;//4

	//v.clear();
	//v.push_back("CC");
	//v.push_back("AA");
	//v.push_back("AA");
	//v.push_back("CC");
	//cout << solution(4, 2, v) << endl;//8

	//v.clear();
	//v.push_back("FF");
	//v.push_back("AA");
	//v.push_back("CC");
	//v.push_back("AA");
	//v.push_back("AA");
	//v.push_back("CC");
	//v.push_back("DD");
	//v.push_back("FF");
	//cout << solution(8, 2, v) << endl;//8

	//v.clear();
	//v.push_back("HGNHU");
	//v.push_back("CRSHV");
	//v.push_back("UKHVL");
	//v.push_back("MJHQB");
	//v.push_back("GSHOT");
	//v.push_back("MQMJJ");
	//v.push_back("AGJKK");
	//v.push_back("QULKK");
	//cout << solution(8, 5, v) << endl;//8

	v.clear();
	v.push_back("KKNKK");
	v.push_back("KKSKK");
	v.push_back("UKHVL");
	v.push_back("KKMJJ");
	v.push_back("KKJKK");
	v.push_back("KKLKK");
	cout << solution(8, 5, v) << endl;//8
	
	return 0;
}