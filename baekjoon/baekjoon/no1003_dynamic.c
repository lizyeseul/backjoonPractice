#include<stdio.h>
int main() {
	int zero[41], one[41];
	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;
	for (int i = 2; i < 42; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", zero[n], one[n]);
	}
	return 0;
}

/*

메모이제이션 방식 : 메모(저장)해놓고 재귀함수 돌 때 값이 저장되어 있으면 그거 사용



*/