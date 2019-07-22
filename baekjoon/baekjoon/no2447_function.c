#include<stdio.h>
#include<math.h>

#define max 6562

int star[max][max] = { 0, };
void print(int n);
void Check(int n, int size, int x, int y);

int main() {
	int n;
	scanf("%d", &n);

	Check(n, n, 0, 0);
	print(n);

	return 0;
}

void Check(int n, int size, int x, int y) {
	//printf("size %2d,  x %2d,  y %2d\n", size, x, y);
	if (size == 3 && star[x + 1][y + 1] == 0) {
		star[x + 1][y + 1] = 1;
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tSize = size / 3;
			int tX = x + (i*tSize);
			int tY = y+(j*tSize);
			//printf("size %2d,  x %2d,  y %2d\n", tSize, tX, tY);
			if (i == 1 && j == 1) {
				for (int w = tX; w < tX + tSize; w++) {
					for (int h = tY; h < tY + tSize; h++) {
						star[w][h] = 1;
					}
				}
			}
			else {
				Check(n, tSize, tX, tY);
			}
		}
	}

}

void print(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (star[i][j] == 1) {
				printf(" ");
			} else{
				printf("*");
			}
		}
		if(i!= n)
			printf("\n");
	}
}
