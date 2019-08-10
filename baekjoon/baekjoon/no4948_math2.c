#include<stdio.h>
#include<math.h>
char isSosu(int s);
char sosu[246913];
int quest[10000];
int main() {
	int input, index=0;
	scanf("%d", &input);
	
	while (input != 0) {
		quest[index] = input;
		index++;
		scanf("%d", &input);
	}

	for (int i = 0; i < 246913; i++) {
		sosu[i] = isSosu(i);
	}

	for (int i = 0; i < index; i++) {
		int q = quest[i];
		int count = 0; 
		for (int k = q; k <= q * 2; k++) {
			count += sosu[k];
		}
		printf("%n", count);
		if (i < index - 1)	printf("\n");
	}

	
	return 0;
}
char isSosu(int s) {
	if (s == 1)
		return 1;
	else if (s == 2 || s%2==0)
		return 0;
	for (int temp = 2; temp <= sqrt(s); temp++) {
		if (s%temp == 0) {
			return 0;
		}
	}
	return 1;
}