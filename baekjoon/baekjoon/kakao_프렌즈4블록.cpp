#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int block[30][30];
//1:블록 있음 0:지울수 있는 블록 -1:블록없음

void checkPang(int x, int y, vector<string> board) {
	if (block[x][y] == -1) {
		return;
	}
	if (board[x][y] == board[x + 1][y]
		&& board[x + 1][y] == board[x][y + 1]
		&& board[x][y + 1] == board[x + 1][y + 1]) {
		printf("+%d %d\n", x, y);
		block[x][y] = 0;
		block[x+1][y] = 0;
		block[x][y+1] = 0;
		block[x+1][y+1] = 0;
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	for (int i = 0; i < m; i++) {
		fill(block[i], block[i] + n, 1);
	}

	queue<int> none, exist;

	//while (true) {
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < m - 1; j++) {
				checkPang(i, j, board);
			}
		}

		printf("---------------------------\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%2d ", block[i][j]);
			}
			printf("\n");
		}
		printf("---------------------------\n");

		int ex = -1;
		for (int j = 0; j < m; j++) {
			for (int i = m-1; i >=0; i--) {
				if (block[i][j] == -1) {
					ex = i;
					break;
				}
				if (!none.empty() && block[i][j] == 1) ex = i;
				else if (block[i][j] == 0) {
					none.push(i);
				}
				if (!none.empty() && ex!=-1) {
					int pre = none.front();
					none.pop();
					int cur = ex;
					ex=-1;
					//dur -> pre
					board[pre].replace(j, 1, board[cur], j, 1);
					board[cur].replace(j, 1, "x");
					block[pre][j] = 1;
					block[cur][j] = -1;
					printf("---------------------------\n");
					printf("pre : %d, cur : %d\n", pre, cur);
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							printf("%2d ", block[i][j]);
						}
						printf("\n");
					}
					printf("---------------------------\n");
				}
			}
			while (!none.empty()) {
				block[none.front()][j] = -1;
				none.pop();
			}
			while (ex>=0) {
				block[ex][j] = -1;
				ex--;
			}
			printf("---------------------------\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					printf("%2d ", block[i][j]);
				}
				printf("\n");
			}
			printf("---------------------------\n");

		}
	//}




	return answer;
}
int main() {
	vector<string> v;
	v.push_back("TTTANT");
	v.push_back("RRFACC");
	v.push_back("RRRFCC");
	v.push_back("TRRRAA");
	v.push_back("TTMMMF");
	v.push_back("TMMTTJ");
	printf("%d\n", solution(6, 6, v));//14

	/*
	v.clear();
	v.push_back("CCBDE");
	v.push_back("AAADE");
	v.push_back("AAABF");
	v.push_back("CCBBF");
	printf("%d\n", solution(4, 5, v));//15

	v.clear();
	v.push_back("AA");
	v.push_back("AA");
	printf("%d\n", solution(2, 2, v));//4

	v.clear();
	v.push_back("AA");
	v.push_back("AA");
	v.push_back("AB");
	printf("%d\n", solution(3, 2, v));//4

	v.clear();
	v.push_back("CC");
	v.push_back("AA");
	v.push_back("AA");
	v.push_back("CC");
	printf("%d\n", solution(4, 2, v));//8

	v.clear();
	v.push_back("FF");
	v.push_back("AA");
	v.push_back("CC");
	v.push_back("AA");
	v.push_back("AA");
	v.push_back("CC");
	v.push_back("DD");
	v.push_back("FF");
	printf("%d\n", solution(4, 2, v));
	*/
	return 0;
}