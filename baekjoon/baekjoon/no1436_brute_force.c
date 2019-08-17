#include<stdio.h>
int isDevil(int n);
int main() {
	int n;
	scanf("%d", &n);

	int count = 0, i=666;
	while (count != n) {
		if (isDevil(i) == 1) {
			count++;
		}
		i++;
	}
	printf("%d", i-1);
	
	return 0;
}
int isDevil(int n) {
	int six = 0;
	while (n > 0) {
		if (n % 10 == 6) {
			six++;
			if (six == 3) {
				return 1;
			}
		}
		else {
			six = 0;
		}
		n /= 10;
	}
	return 0;
}