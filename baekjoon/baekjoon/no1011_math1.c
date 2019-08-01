#include<stdio.h>
#include<math.h>
int main() {
	int t, result[10000];
	unsigned int length[10000];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		length[i] = y - x;
	}

	for (int i = 0; i < t; i++) {
		int l = length[i];
		unsigned int count = 1, temp=0, a=1,b=0;
		for(count=1; ; count++) {
			if (count % 2 == 1) {
				temp = a * (a - 1) + 1;
				if (temp > l) break;
				b++;
			}
			else {
				temp = b*b + 1;
				if (temp > l) break;
				a++;
			}
		}
		printf("%ld", a+b-1);
		if (i < t - 1)	printf("\n");
	}
	return 0;
}