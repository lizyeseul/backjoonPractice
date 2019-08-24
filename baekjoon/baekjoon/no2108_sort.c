#include<stdio.h>
int sort[1000];
void quick(int s, int e);
void swap(int a, int b);
int main()
{
	int n;
	scanf("%d", &n);
	int total = 0;
	int min=0, max=0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &sort[i]);
		total += sort[i];
		if (i == 0) {
			min = sort[i];
			max = sort[i];
		} 
		if(min > sort[i]) {
			min = sort[i];
		}
		else if (max < sort[i]) {
			max = sort[i];
		}
	}
	int avg;
	if (total < 0) {
		avg = total / (n-1);
	}
	else if (total == 0) {
		avg = 0;
	}
	else {
		avg = total / n;
	}
	int round = max - min;

	quick(0, n - 1);

	int middle = sort[n / 2];

	int* count = (int*)malloc(sizeof(int)*n);
	for (int i = 1; i < n; i++) {
		count[i] = 0;
	}
	int cMax = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			count[0] = 1;
			cMax = count[0];
			continue;
		}
		if (sort[i] == sort[i - 1]) {
			count[i] = count[i-1] + 1;
			if (count[i] > cMax) {
				cMax = count[i];
			}
		}
		else {
			count[i] = 1;
		}
	}
	int index = 0,flag = 0;
	for (int i = 0; i < n; i++) {
		if (count[i] == cMax) {
			if (flag == 0) {
				index = i;
				flag = 1;
			}
			else {
				index = i;
				break;
			}
		}
	}


	printf("%d\n", avg);
	printf("%d\n", middle);
	printf("%d\n", sort[index]);
	printf("%d", round);
	return 0;
}
void quick(int s, int e) {
	if (e - s <= 1) {
		if (sort[s] > sort[e] && s == e - 1) {
			swap(s, e);
		}
		return;
	}

	int start = s, end = e;
	int p = sort[(e - s) / 2];
	while (s < e) {
		while (sort[s] < p && end > s) {
			s++;
		}
		while (sort[e] > p && start < e) {
			e--;
		}
		swap(s, e);
		if (end > s)
			s++;
		if (start < e)
			e--;
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