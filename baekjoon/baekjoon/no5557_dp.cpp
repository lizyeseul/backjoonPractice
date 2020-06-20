#include<stdio.h>
#include<algorithm>
using namespace std;
#define p(idx, num) 0<=idx+num && idx+num <=20
#define m(idx, num) 0<=idx-num && idx-num <=20
#define ull unsigned long long
int main() {
	int n;
	scanf("%d", &n);
	ull count[21];
	ull plus[21];
	ull minus[21];
	fill(count, count + 21, 0);
	fill(plus, plus + 21, 0);
	fill(minus, minus + 21, 0);

	int num;
	scanf("%d", &num);
	count[num] = 1;
	int idx = 0;
	for (int i = 0; i < n-2; i++)
	{
		scanf("%d", &num);
		fill(plus, plus + 21, 0);
		fill(minus, minus + 21, 0);
		if (num == 0) {
			for (idx = 0; idx <= 20; idx++) {
				count[idx] *= 2;
			}
		}
		else {
			for (idx = 0; idx <= 20; idx++) {
				if (p(idx, num)) plus[idx] = count[idx + num];
				if (m(idx, num)) minus[idx] = count[idx - num];
			}
			for (idx = 0; idx <= 20; idx++) {
				count[idx] = plus[idx] + minus[idx];
			}
		}
	}
	scanf("%d", &num);
	printf("%lld", count[num]);
	return 0;
}