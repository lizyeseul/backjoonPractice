#include<stdio.h>
int main() {
	/*
	A ���� ���
	B ���� ���
	C ��Ʈ�� ���
	���ͺб��� --> �Ǹź��(C*�ǸŴ��) > �� ���(������� + �������)
	c * sales > a+ b*sales
	(c-b)*sales > a
	*/
	//2000000000 1 2000000000
	//1000 50 170
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int sales = (a / (c-b))+1;
	if (b >= c) {
		sales = -1;
	}
	/*int sales = 0;
	int saleMoney = c * sales;
	int totalMoney = a + b * sales;

	printf("%8d %8d\n", saleMoney, totalMoney);
	while (saleMoney <= totalMoney) {
		sales++;
		saleMoney = c * sales;
		totalMoney = a + b * sales;
		printf("%8d %8d\n", saleMoney, totalMoney);
	}*/
	printf("%d", sales);
	
	return 0;
}