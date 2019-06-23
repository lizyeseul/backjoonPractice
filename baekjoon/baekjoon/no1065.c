/*
N보다 작거나 같은 한수 출력
한수 : 각 자리수가 등차수열을 이루는 경우
*/
#include<stdio.h>
void check(int n);

int main() {

	int num;
	scanf("%d", &num);

	check(num);
	return 0;
}


void check(int n)
{
	int num = n;
	if (num <= 99) {
		printf("%d", num);
	}
	else {
		int count = 99;

		for (int i = 100; i <= num; i++)
		{
			if ((num % 10) - (num / 10 % 10) == (num / 10 % 10) - (num / 100)) {
				count++;
			}
		}

		printf("%d", count);
		
	}
}
