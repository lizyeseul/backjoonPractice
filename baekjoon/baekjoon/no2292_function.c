#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);

		int cur = 1;
		if (n == 1) {
			cur = 1;
		}
		else {
			n -= 1;
			cur++;
			//printf("c %d   n %d\n", cur, n);
			while (n > (cur - 1) * 6) {
				n -= (cur - 1) * 6;
				cur++;
				//printf("c %d   n %d\n", cur, n);
			}
		}
		//printf("n=%d   cur=%d\n", N, cur);
		printf("%d", cur);



	return 0;
}