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
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int sales = (a / (c-b))+1;
	if (b >= c) {
		sales = -1;
	}
	printf("%d", sales);
	
	return 0;
}