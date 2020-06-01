#include<stdio.h>
int main() {
	int coin;
	scanf("%d", &coin);
	coin = 1000 - coin;
	int total = 0,count;
	int change[6] = { 500,100,50,10,5,1 };
	for (int i = 0; i < 6; i++) {
		count = coin / change[i];
		total += count;
		coin -= count* change[i];
	}
		printf("%d", total);
	return 0;
}