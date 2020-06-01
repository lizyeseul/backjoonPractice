#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int *h = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = n-1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (h[j] >= h[i]) {
				h[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(h[j] == i) printf("%d ", j+1);
		}
	}
	return 0;
}