#include<stdio.h>
int main() {
	int a, b, v;
	scanf("%d%d%d", &a,&b,&v);

	if (v <= a) {
		printf("1");
	}
	else {
		v -= a;
		if (v <= (a - b)) {
			printf("2");
		}
		else if ((v % (a - b)) == 0) {
			printf("%d", v / (a - b)+1);
		}
		else {
			printf("%d", v /(a-b) +2 );
		}
	}
	
	return 0;
}