#include<stdio.h>
int tab[21] = { 0, };
int N;
void print();
void ha(int n, int from, int to);
int main() {
	scanf("%d", &N);
	for (int i = 0; i <= N; i++) {
		tab[i] = 1;
	}
	int count = 1;
	for (int i = 0; i < N; i++) {
		count *= 2;
	}
	printf("%d", count-1);
	ha(N, 1, 3);
	return 0;
}
void ha(int n, int from, int to) {
	if (n == 0)	return;
	ha(n - 1, from, 6 - from - to);
	int pre = tab[n];
	tab[n] = to;
	printf("\n%d %d", pre, to);
	//print();
	ha(n - 1, 6-from-to, to);
}
void print() {
	for (int i = 1; i <= N; i++) {
		printf("%2d ", i);
	}
	printf("\n");
	for (int i = 1; i <= N; i++) {
		printf("%2d ", tab[i]);
	}
	printf("\n\n");
}