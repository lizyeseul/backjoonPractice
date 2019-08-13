#include<stdio.h>
#include<math.h>
int main() {
	int x1, y1, r1, x2, y2, r2;
	int t;
	int result[1000];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

		int x = x1 - x2;
		int y = y1 - y2;
		double d = sqrt(x*x + y * y);
		int R = r1 + r2;
		int r = r1 - r2;
		if (r < 0)
			r *= -1;

		if (x1 == x2 && y1 == y2 && r1 == r2) {//6
			result[i] = -1;
		}
		else if (x1 == x2 && y1 == y2 && r1 != r2) {//5?
			result[i] = 0;
		}
		else if (r>d) {//5?
			result[i] = 0;
		}
		else if (r == d) {
			result[i] = 1;
		}
		else if (R > d) {//3
			result[i] = 2;
		}
		else if (R < d) {//1
			result[i] = 0;
		}
		else if (R == d) {//2
			result[i] = 1;
		}
		
	}

	for (int i = 0; i < t; i++) {
		printf("%d\n",result[i]);
	}
	return 0;
}