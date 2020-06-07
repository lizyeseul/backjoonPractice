#include<stdio.h>
int w, h;
int island[50][50];
bool check[50][50];

int move[8][2] = { {-1,-1}, {-1,0}, {-1,1},{0,-1}, {0,1}, {1,-1},{1,0},{1,1} };
bool isIn(int x, int y) {
	return 0 <= x && x < h && 0 <= y && y < w;
}

void dp(int x, int y) {
	if (isIn(x, y) == false || check[x][y] == true) {
		return;
	}
	check[x][y] = true;
	for (int t = 0; t < 8; t++) {
		int nextX = x+move[t][0];
		int nextY = y+move[t][1];
		dp(nextX, nextY);
	}
	return;
}
int main() {
	while (true) {
		scanf("%d%d", &w, &h);
		if (w == 0 && h == 0) return 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &island[i][j]);
				check[i][j] = island[i][j] == 0 ? true : false;
			}
		}

		int total = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (check[i][j] == false && island[i][j] == 1) {//¹æ¹® ¾ÈÇÑ ¼¶
					total++;
					dp(i, j);
				}
			}
		}
		printf("%d\n", total);
	}
	return 0;
}