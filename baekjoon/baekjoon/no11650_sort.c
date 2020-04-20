#include<stdio.h>
struct cd {
	int x;
	int y;
};
struct cd temp[100000];
struct cd xy[100000];
int isBig(struct cd a, struct cd b);
void partition(int start, int end);
void merge(int start, int middle, int end);
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &xy[i].x, &xy[i].y);
	}

	//sorting
	partition(0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", xy[i].x, xy[i].y);
	}
	return 0;
}


void partition(int start, int end)
{
	
	if (start >= end) {
		return;
	}
	int middle = (start + end) / 2;
	partition(start, middle);
	partition(middle + 1, end);
	
	merge(start, middle, end);
}
void merge(int start, int middle, int end) {
	int left = start;
	int right = middle + 1;
	int index = start;
	while (left <= middle && right <= end) {
		if (isBig(xy[left], xy[right]) == 0) {
			temp[index] = xy[left];
			left++;
		} else if (isBig(xy[left], xy[right]) == 1) {
			temp[index] = xy[right];
			right++;
		}
		index++;
	}
	if (left > middle) {
		for (int i = right; i <= end; i++) {
			temp[index] = xy[i];
			index++;
		}
	}
	else {
		for (int i = left; i <= middle; i++) {
			temp[index] = xy[i];
			index++;
		}
	}
	for (int i = start; i <= end; i++) {
		xy[i] = temp[i];
	}
}


int isBig(struct cd a, struct cd b) {
	if (a.x == b.x) {
		if (a.y < b.y) {
			return 0;//a가 더 작음
		}
		else {
			return 1;
		}
	}
	else if (a.x < b.x) {
		return 0;
	}
	else {
		return 1;
	}
}
