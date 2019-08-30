#include<stdio.h>
unsigned long t(int n);
unsigned long tri[101] = { 0, };
int main() {
	int T;
	scanf("%d", &T);
	tri[1] = 1; tri[2] = 1; tri[3] = 1;
	for (int i = 0; i < T; i++) {
		int num;
		scanf("%d", &num);
		printf("%lld\n", t(num));
	}
	return 0;
}
unsigned long t(int n) {
	if (tri[n] == 0) {
		tri[n] = t(n - 3) + t(n - 2);
		return t(n - 3) + t(n - 2);
	}
	return tri[n];
}