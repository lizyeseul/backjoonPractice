#include<stdio.h>
int sort[10] = {3,9,4,7,5,0,1,6,8,2};
void quick(int s, int e);
void swap(int a, int b);
void print();
int main() {
	print();
	quick(0, 9);
	return 0;
}
void quick(int s, int e) {
	printf("++++++%d ~ %d\n", s, e);
	if (e-s <= 1) {
		if (sort[s] > sort[e] && s == e - 1) {
			swap(s, e);
			print();
		}
		return;
	}

	int start=s, end = e;
	int p = sort[(e - s) / 2];
	printf("pivot : %d\n", p);
	while (s<e) {
		while (sort[s] < p && end > s) {
			s++;
		}
		while (sort[e] > p && start < e) {
			e--;
		}
		swap(s, e);
		print();
		if(end > s)
			s++;
		if(start < e)
			e--;
		//printf("s : %d, e : %d\n", s, e);
	}
	
	if (s == e && end > s)
		s++;
		
	quick(start, s - 1);
	quick(s, end);
}
void swap(int a, int b) {
	int temp = sort[a];
	sort[a] = sort[b];
	sort[b] = temp;
}
void print() {
	for (int i = 0; i < 10; i++) {
		printf("%2d ", sort[i]);
	}
	printf("\n");
}