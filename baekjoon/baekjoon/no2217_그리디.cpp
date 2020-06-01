#include<stdio.h>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
	return b < a;
}
int main() {
	int n;
	scanf("%d", &n);
	int *rope = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &rope[i]);
	}
	sort(rope, rope + n,compare);
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (m < rope[i] * (i+1)) {
			m = rope[i] * (i + 1);
		}
	}
	printf("%d", m);
	return 0;
}
