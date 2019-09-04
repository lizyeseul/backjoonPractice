#include<stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int main(){
	int n;
	scanf("%d", &n);

	int score[300] = { 0, };
	int total[300] = { 0, };
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
	}
	total[0] = score[0];
	total[1] = score[0]+score[1];
	total[2] = max(score[0],score[1]) + score[2];

	if (n > 2) {
		for (int i = 3; i < n; i++) {
			total[i] = max(total[i - 3] + score[i - 1], total[i - 2]) + score[i];
		}
	}
	printf("%d", total[n-1]);
	return 0;
}