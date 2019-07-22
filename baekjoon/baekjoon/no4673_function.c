

/*
* self number
* d(n) = n+각 자리수 합 -> self number
* 10000이하의 self number 아닌 수 출력
*/
#include <stdio.h>

int selfNum(int n);
int isSelfNum(int n);

void main()
{

	for (int i = 0; i < 10000; i++)
	{
		if (isSelfNum(i) == 0) {
			printf("%d\n", i);
		}
	}

}

int isSelfNum(int n)
{
	int min = n - 36;
	if (min < 0) {
		min = 0;
	}
	for (int j = n - 36; j <= n; j++) {
		if (selfNum(j) == n) {
			return 1;
		}
	}
	return 0;
}

int selfNum(int n)
{
	int self = n;
	int tempNum = n;
	while (tempNum > 0) {
		self += tempNum % 10;
		tempNum /= 10;
	}
	return self;
}