#include<stdio.h>
char line[1000];
int n;
struct home* h;
int total = 3001;

int isNext(int depth, char color, int pre);
int min(int a, int b, int c);

struct home {
	int r, g, b;
};

int main() {
	scanf("%d", &n);
	h = (struct home*) malloc(sizeof(struct home)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &h[i].r, &h[i].g, &h[i].b);
	}

	isNext(0, 'a',0);
	printf("%d", total);

	return 0;
}
int isNext(int depth, char color, int pre) {
	if (depth == n - 1) {
		if (total > pre + min(h[depth].r, h[depth].g, h[depth].b)) {
			int r = h[depth].r;
			int g = h[depth].g;
			int b = h[depth].b;
			if (color == 'r')	r = 1001;
			else if (color == 'g')	g = 1001;
			else if (color == 'b')	b = 1001;
			total = pre + min(r,g,b);
		}
		return 0;
	}

	if (pre > total) {
		return 0;
	}


	if (color != 'r'){
		isNext(depth + 1, 'r', pre + h[depth].r);
	}
	if (color != 'g') {
		isNext(depth + 1, 'g', pre + h[depth].g);
	}
	if (color != 'b') {
		isNext(depth + 1, 'b', pre + h[depth].b);
	}

	return 0;
}
/*
3
26 40 83
49 60 57
13 89 99
*/
int min(int a, int b, int c) {
	if (a < b) {
		if (a < c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b < c) {
			return b;
		}
		else {
			return c;
		}
	}
}