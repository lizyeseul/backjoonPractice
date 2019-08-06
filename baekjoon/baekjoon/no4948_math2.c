#include<stdio.h>
int isSosu(int s);
int main() {

	int s[10000];
	scanf("%d", &s[0]);
	int index = 0;
	while(s[index]!=0){
		index++;
		scanf("%d", &s[index]);
	}

	for (int k = 0; k < index; k++) {
		int count = 0;
		for (int i = s[k]; i <= s[k] * 2; i++) {
			if (isSosu(i) == 1) {
				printf("+%d", i);
				count++;
			}
		}
		printf("%d", count);
		if(k < index-1) {
			printf("\n");
		}
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