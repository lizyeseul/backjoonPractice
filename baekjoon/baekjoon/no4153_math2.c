#include<stdio.h>
int max(int a, int b, int c);
int isTri(int a, int b, int c);
int main() {
	int a[10000], b[10000], c[10000];
	int index = 0;
	scanf("%d%d%d", &a[index], &b[index], &c[index]);

	while (!(a[index] == 0 && b[index] == 0 && c[index] == 0)) {
		index++;
		scanf("%d%d%d", &a[index], &b[index], &c[index]);
	}
	for (int i = 0; i < index; i++) {
		int A = a[i], B = b[i], C = c[i];
		int com = max(A, B, C);
		int flag = 0;
		switch (com) {
			case 1:
				if (A*A == B * B + C * C)
					flag = 1;
				break;
			case 2:
				if (B * B == A * A + C * C)
					flag = 1;
				break;
			case 3:
				if (C * C == B * B + A * A)
					flag = 1;
				break;
		}
		if (flag == 1)
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}
int max(int a, int b, int c) {
	if (a > b) {
		if (c > a) {
			return 3;
		} else {
			return 1;
		}
	} else if(b > a){
		if (b > c) {
			return 2;
		}
		else  {
			return 3;
		}
	}
}