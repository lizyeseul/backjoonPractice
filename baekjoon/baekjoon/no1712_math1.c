#include<stdio.h>
int main() {
	/*
	A 고정 비용
	B 가변 비용
	C 노트북 비용
	손익분기점 --> 판매비용(C*판매대수) > 총 비용(고정비용 + 가변비용)
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