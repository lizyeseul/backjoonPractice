#include<stdio.h>
#define M_PI 3.1415926535897937
int main() {
	int r;
	scanf("%d", &r);

	printf("%.6f\n", M_PI * r * r);
	double t = 2 * r*r;
	printf("%.6f", t);
	
	return 0;
}