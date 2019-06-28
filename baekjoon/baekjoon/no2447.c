#include<stdio.h>
#include<math.h>

void print(int n, int height);
int check(int n, int height, int w, int h);
int main() {
	int n;
	scanf("%d", &n);
	int k = log(n) / log(3);

	print(n, k);

	return 0;
}

void print(int n, int height) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check(n, height, j, i) == 1) {
				printf(" ");
			} else{
				printf("*");
			}
		}
		if(i!= n)
			printf("\n");
	}
}

int check(int n, int height, int w, int h) {
	int flag = 0;
	for (int p = height; p > 0; p--) {
		int wei = w, hei = h;

		int range1 = 1;
		for (int r = 1; r < p; r++) {
			range1 *= 3;
		}
		int range2 = range1 * 2;

		wei %= range1 * 3;
		hei %= range1 * 3;

		if ((range1 < wei && wei <= range2) && (range1 < hei && hei <= range2)) {
				flag = 1;
		}
		
	}
	return flag;
}