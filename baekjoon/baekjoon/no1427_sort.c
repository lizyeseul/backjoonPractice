#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int num[15];
	int index=0;
	while (n >= 10) {
		num[index] = n % 10;
		n /= 10;
		index++;
	}
	num[index] = n;
	for (int i = 0; i < index; i++) {
		for (int k = i+1; k <= index; k++) {
			if (num[i] > num[k]) {
				int temp = num[i];
				num[i] = num[k];
				num[k] = temp;
			}
		}
	}
	int result = 0;
	for (int i = index; i >= 0; i--) {
		result += num[i];
		if(i!=0)
			result *= 10;
	}
	printf("%d", result);
	return 0;
}