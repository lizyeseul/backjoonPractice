#include<stdio.h>
int main() {
	int x, y, w, h;
	scanf("%d%d%d%d", &x, &y, &w, &h);

	int min=w-x;
	if (h - y < min)
		min = h - y;
	if (x < min)
		min = x;
	if (y < min)
		min = y;
	printf("%d", min);
	return 0;
}