/*
N���� �۰ų� ���� �Ѽ� ���
�Ѽ� : �� �ڸ����� ���������� �̷�� ���
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
			if ((i % 10) - (i / 10 % 10) == (i / 10 % 10) - (i / 100)) {
				count++;
			}
		}

		printf("%d", count);
		
	}
}