#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int time[1000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &time[i]);
	}
	sort(time, time + n, greater<int>());
	long long total = 0;
	for (int i = 1; i <= n; i++) {
		total += time[i-1] * i;
	}
	printf("%lld", total);
	return 0;
}