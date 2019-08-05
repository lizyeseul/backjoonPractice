#include<stdio.h>
int isSosu(int s);
int main() {
	int m, n;
	int total = 0, min = 0, flag=0;
	scanf("%d%d", &m, &n);
	for (int i = m; i <= n; i++) {
		if (isSosu(i) == 1) {
			total += i;
			if (flag == 0) {
				min = i; 
				flag = 1;
			}
		}
	}
	if (total == 0) {
		printf("-1");
	}
	else {
		printf("%d\n%d", total, min);
	}
	return 0;
}
int isSosu(int s) {
	if (s == 1)
		return 0;
	else if (s == 2)
		return 1;
	for (int temp = 2; temp < s / 2 + 1; temp++) {
		if (s%temp == 0) {
			return 0;
		}
	}
	return 1;
}