#include<stdio.h>
struct dot {
	int x, y;
};
int main() {
	struct dot d[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &d[i].x, &d[i].y);
	}

	int x, y;
	
	if (d[0].x == d[1].x)
		x = d[2].x;
	else if (d[0].x == d[2].x)
		x = d[1].x;
	else
		x = d[0].x;

	if (d[0].y == d[1].y)
		y = d[2].y;
	else if (d[0].y == d[2].y)
		y = d[1].y;
	else
		y= d[0].y;

	printf("%d %d", x, y);
	return 0;
}