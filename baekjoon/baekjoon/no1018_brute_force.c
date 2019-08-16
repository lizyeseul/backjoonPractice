#include<stdio.h>
#include<string.h>

char chess[50][50];
int find(int startX, int startY);
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
			scanf("%s", &chess[i]);
	}
	
	int min = 64;
	for (int i = 0; i <= n - 8; i++) {
		for (int k = 0; k <= m - 8; k++) {
			int f = find(i, k);
			if (f < min) {
				min = f;
			}
		}
	}
	printf("%d",min);

	return 0;
}
int find(int startX, int startY) {
	int count=0;
	for (int h = startX; h < startX+8; h++) {
		for (int w = startY; w < startY+8; w++) {
			if ((h + w) % 2 == 0) {
				if (chess[h][w] == 'W')
					count++;
			}
			else {
				if (chess[h][w] == 'B')
					count++;
			}
			//printf("%c", chess[h][w]);
		}
	}
	if (count > 32) {
		count = 64 - count;
	}
	return count;
}