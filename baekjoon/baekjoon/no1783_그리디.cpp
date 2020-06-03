#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n,m;
	scanf("%d%d", &n,&m);
	int count = 1;
	if (n >= 3) {
		if (m >= 7) {
			count = m - 2;
		}
		else {
			count = min(m,4);
		}
	}
	else if (n == 2) {
		count = min(4, (m + 1) / 2);
	}
	else if (n == 1) {
		count = 1;
	}
	printf("%d", count);
	return 0;
}