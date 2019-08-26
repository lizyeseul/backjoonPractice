#include<stdio.h>
int main() {
	int num;
	scanf("%d", &num);

	if (num == 1 || num==2) {
		printf("1");
	}
	else {
		long long* p = malloc(sizeof(long long)*num);
		p[0] = 1;
		p[1] = 1;
		for (int i = 2; i < num; i++) {
			p[i] = p[i - 2] + p[i - 1];
		}
		printf("%lu", p[num - 1]);
	}
	return 0;
}