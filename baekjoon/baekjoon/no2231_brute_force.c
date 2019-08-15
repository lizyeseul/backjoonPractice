#include<stdio.h>
#include<math.h>
int main() {
	int n;
	scanf("%d", &n);

	int temp = n, d=0;
	while (temp >= 10) {
		temp /= 10;
		d++;
	}
	int flag = 0;
	
	for (int i = n - d * 9; i < n; i++) {
		int total = 0;
		temp = i;
		for (int k = 0; k <= d; k++) {
			total += temp % 10;
			temp /= 10;
		}
		if (n == total+i) {
			printf("%d", i);
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("0");
	}
	return 0;
}