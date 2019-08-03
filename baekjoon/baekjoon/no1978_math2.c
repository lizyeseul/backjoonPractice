#include<stdio.h>
int main() {
	int t, sosu[101];
	scanf("%d", &t);
	int count = 0;
	for (int i = 0; i < t; i++) {
		scanf("%d", &sosu[i]);
	}
	for (int i = 0; i < t; i++) {
		int s = sosu[i];
		if (s == 2)
			count++;
		else if (s >= 3)
			count += isSosu(s);
	}
	printf("%d", count);
	return 0;
}
int isSosu(int s) {
	//printf("s %d  ", s);
	for (int temp = 2; temp < s / 2+1; temp++) {
		if (s%temp == 0) {
			//printf("-0\n");
			return 0;
		}
	}
	//printf("-1\n");
	return 1;
}