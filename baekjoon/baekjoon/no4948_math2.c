#include<stdio.h>
#include<math.h>
int isSosu(int s);
int main() {
	int input;

	for (int i = 0; i < 123456; i++) {
		scanf("%d", &input);
		if (input == 0)
			break;
		int count = 0;
		for (int k = input + 1; k < 2 * input + 1; k++) {
			if (isSosu(k) == 1)
				count++;
		}
		printf("%d\n", count);
	}
	
	return 0;
}
int isSosu(int s) {
	if (s == 1)
		return 0;
	else if (s == 2 || s%2==0)
		return 1;
	for (int temp = 2; temp <= sqrt(s); temp++) {
		if (s%temp == 0) {
			return 0;
		}
	}
	return 1;
}