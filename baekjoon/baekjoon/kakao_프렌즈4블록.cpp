#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int block[30][30];
int same[4][2] = { {0,0},{1,0},{0,1},{1,1} };
bool checkPang(int x, int y, vector<vector<char> > board2) {
	if (y + 1 > board2[x + 1].size() - 1) return false;
	bool answer = false;
	if (board2[x][y] == board2[x + 1][y]
		&& board2[x + 1][y] == board2[x][y + 1]
		&& board2[x][y + 1] == board2[x + 1][y + 1]) {
		for (int k = 0; k < 4; k++) {
			if (block[x + same[k][0]][y + same[k][1]] != 0) {
				block[x + same[k][0]][y + same[k][1]] = 0;
				board2[x + same[k][0]][y + same[k][1]] = 'x';
				answer = true;
			}
		}
	}
	return answer;
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	vector<vector<char> > board2;
	board2.resize(n);
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			board2[j].push_back(board[i][j]);
		}
	}
	for (int i = 0; i < n; i++) fill(block[i], block[i] + m, 1);

	bool change;
	while (true) {
		change = false;
		for (int i = 0; i < board2.size(); i++) {
			if (board2[i].size() == 1 && board2[i][0] != 'e') {
				board2[i].push_back('t');
				board2[i].erase(board2[i].begin(), board2[i].begin() + 1);
			}
			else {
				if (i == board2.size() - 1) continue;
				for (int j = 0; j < board2[i].size() - 1; j++) {
					change = checkPang(i, j, board2) == true ? true : change;
				}
			}
		}
		if (change == false) break;
		else change = false;

		for (int i = 0; i < board2.size(); i++) {
			for (int j = 0; j < board2[i].size(); j++) {
				board2[i][j] = block[i][j] == 0 ? 'x' : board2[i][j];
			}
		}

		for (int i = 0; i < board2.size(); i++) {
			bool check = false;
			vector<char>::iterator iter;
			for (iter = board2[i].begin(); iter != board2[i].end(); ) {
				if ((*iter) == 'x') {
					if (iter + 1 == board2[i].end() && check == false) {
						board2[i].push_back('e');
						iter = board2[i].erase(iter);
					}
					else iter = board2[i].erase(iter);
				}
				else {
					check = true;
					++iter;
				}
			}
			fill(block[i], block[i] + m, 1);
		}

	}

	for (int i = 0; i < board2.size(); i++) {
		if (board2[i][0] == 'e') continue;
		answer += board2[i].size();
	}
	return m * n - answer;
}
int main() {
	vector<string> v;
	v.push_back("TTTANT");
	v.push_back("RRFACC");
	v.push_back("RRRFCC");
	v.push_back("TRRRAA");
	v.push_back("TTMMMF");
	v.push_back("TMMTTJ");
	cout << solution(6, 6, v) << endl;//15

	
	v.clear();
	v.push_back("CCBDE");
	v.push_back("AAADE");
	v.push_back("AAABF");
	v.push_back("CCBBF");
	cout << solution(4, 5, v) << endl;//14

	v.clear();
	v.push_back("aa");
	v.push_back("aa");
	cout << solution(2, 2, v) << endl;//4

	v.clear();
	v.push_back("aa");
	v.push_back("aa");
	v.push_back("ab");
	cout << solution(3, 2, v) << endl;//4

	v.clear();
	v.push_back("cc");
	v.push_back("aa");
	v.push_back("aa");
	v.push_back("cc");
	cout << solution(4, 2, v) << endl;//8

	v.clear();
	v.push_back("ff");
	v.push_back("aa");
	v.push_back("cc");
	v.push_back("aa");
	v.push_back("aa");
	v.push_back("cc");
	v.push_back("dd");
	v.push_back("ff");
	cout << solution(8, 2, v) << endl;//8

	v.clear();
	v.push_back("hgnhu");
	v.push_back("crshv");
	v.push_back("ukhvl");
	v.push_back("mjhqb");
	v.push_back("gshot");
	v.push_back("mqmjj");
	v.push_back("agjkk");
	v.push_back("qulkk");
	cout << solution(8, 5, v) << endl;//8

	v.clear();
	v.push_back("kknkk");
	v.push_back("kkskk");
	v.push_back("kkhvl");
	v.push_back("kkmjj");
	v.push_back("kkjkk");
	v.push_back("kklkk");
	cout << solution(6, 5, v) << endl;//8
	
	return 0;
}