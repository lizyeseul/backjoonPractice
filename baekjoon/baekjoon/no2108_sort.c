#include<stdio.h>
int main()
{
	int n;
	int sort[1000];
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

	for (int i = 0; i < n - 1; i++) {
		for (int k = i + 1; k < n; k++) {
			if (sort[i] > sort[k]) {
				int temp = sort[i];
				sort[i] = sort[k];
				sort[k] = temp;
			}
		}
	}
	int middle = sort[n / 2];

	int* count = (int*)malloc(sizeof(int)*n);

	int cMax = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			count[0] = 1;
			cMax = count[0];
			continue;
		}
		if (sort[i] == sort[i - 1]) {
			count[i] = count[i] + 1;
			if (count[i] > cMax) {
				cMax = count[i];
			}
		}
		else {
			count[i] = 1;
		}
	}
	int index = 0,flag = 0;
	for (int i = 1; i < n; i++) {
		if (count[i] == cMax) {
			if (flag = 0) {
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