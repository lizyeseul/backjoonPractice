#include<stdio.h>
//#define max 7
#define maxIndex 2
int bf[maxIndex+1] = { 1,2,3 };
int next(int max);
int main() {
	
	int n, m;
	scanf("%d%d", &n, &m);
	
	int card[101];
	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	
	int black = 0;
	do {
		int total = 0;
		for (int i = 0; i <= maxIndex; i++) {
			total += card[bf[i] - 1];
		}
		if (total == m) {
			black = total;
			break;
		}
		if (black < total && total<m) {
			black = total;
		}
	} while (next(n));
	printf("%d", black);
	return 0;
}

int next(int max) {
	if (bf[maxIndex] == max) {
		int index = maxIndex;
		while (bf[index] == (max - (maxIndex -index))) {
			index--;
			if (index < 0)
				break;
		}

		if (index == -1) {
			return 0;
		}
		else {
			bf[index]++;
			for (int k = index + 1; k <= maxIndex; k++) {
				bf[k] = bf[k - 1] + 1;
			}
			return 1;
		}
	}
	else {
		bf[maxIndex] += 1;
		return 1;
	}
}