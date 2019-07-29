#include<stdio.h>
int main() {
	int x;
	scanf("%d", &x);
	int count = 1, total = 0;

		while (x > total) {
			total += count;
			count++;
		}
		count--;
		int l, r;
		int temp = x - (total - count);
		if (count % 2 == 0) {
			l = count -temp +1;
			r = temp;
			printf("%d/%d", r, l);
		}
		else {
			r = count - temp + 1;
			l = temp;
			printf("%d/%d", r, l);
		}
	
	return 0;
}