#include<stdio.h>
int n;
struct home* h;
int min(int a, int b) { if (a < b) return a; else return b; }

struct home {
	int r, g, b;
	int sumR, sumG, sumB;
};

int main() {
	scanf("%d", &n);
	h = (struct home*) malloc(sizeof(struct home)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &h[i].r, &h[i].g, &h[i].b);
	}

	h[0].sumB = h[0].b;
	h[0].sumG = h[0].g;
	h[0].sumR = h[0].r;

	for (int i = 1; i < n; i++) {
		h[i].sumB = h[i].b + min(h[i - 1].sumG, h[i - 1].sumR);
		h[i].sumG = h[i].g + min(h[i - 1].sumR, h[i - 1].sumB);
		h[i].sumR = h[i].r + min(h[i - 1].sumB, h[i - 1].sumG);
	}


	if (h[n - 1].sumB < h[n - 1].sumG) {
		if (h[n - 1].sumB < h[n - 1].sumR) {
			printf("%d", h[n - 1].sumB);
		}
		else {
			printf("%d", h[n - 1].sumR);
		}
	}
	else {
		if (h[n - 1].sumG < h[n - 1].sumR) {
			printf("%d", h[n - 1].sumG);
		}
		else {
			printf("%d", h[n - 1].sumR);
		}
	}


	return 0;
}
