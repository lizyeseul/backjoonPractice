#include<stdio.h>
/*
a : n개 짜리 배열
n : 합 구할 정수의 개수
리턴 : a에 있는 n개의 합
*/
long long sum(int *a, int n) {
	long long total = 0;
	for (int i = 0; i < n; i++) {
		total += a[i];
	}
	return total;
}
