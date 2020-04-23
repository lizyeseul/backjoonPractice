#include<stdio.h>
#include<string.h>

struct student {
	char name[11];
	int korean;
	int english;
	int math;
};

struct student temp[100000];
struct student st[100000];
int dictionary(char a[], char b[]);
int isBig(struct student a, struct student b);
void partition(int start, int end);
void merge(int start, int middle, int end);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d%d", &st[i].name, &st[i].korean, &st[i].english, &st[i].math);
	}
	//sorting
	partition(0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%s\n", st[i].name);
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
		if (isBig(st[left], st[right]) == 0) {//a가 앞순서
			temp[index] = st[left];
			left++;
		}
		else if (isBig(st[left], st[right]) == 1) {
			temp[index] = st[right];
			right++;
		}
		index++;
	}
	if (left > middle) {
		for (int i = right; i <= end; i++) {
			temp[index] = st[i];
			index++;
		}
	}
	else {
		for (int i = left; i <= middle; i++) {
			temp[index] = st[i];
			index++;
		}
	}
	for (int i = start; i <= end; i++) {
		st[i] = temp[i];
	}
}

int dictionary(char a[], char b[]) {
	int alength = strlen(a);
	int blength = strlen(b);
	int index = 0;
	while (alength > 0 && blength > 0) {
		if (a[index] < b[index]) {
			return 0;//a가 더 앞순서
		} else if (a[index] > b[index]) {
			return 1;//b가 더 앞순서
		}
		alength--;
		blength--;
		index++;
	}
	if (alength == 0 && blength == 0) {
		return -1;//같음
	}
	else if (alength > 0) {
		return 1;//b가 더 앞순서
	}
	else if (blength > 0) {
		return 0;//a가 더 앞순서
	}

}
int isBig(struct student a, struct student b) {
	if (a.korean == b.korean) {
		if (a.english == b.english) {
			if (a.math == b.math) {
				return dictionary(a.name, b.name);
			}
			else if (a.math < b.math) {
				return 1;//b가 더 앞순서
			}
			else {
				return 0;//a가 더 앞순서
			}
		}
		else if (a.english > b.english) {
			return 1;//b가 더 앞순서
		}
		else {
			return 0;//a가 더 앞순서
		}
	}
	else if (a.korean < b.korean) {
		return 1;//b가 더 앞순서
	}
	else {
		return 0;//a가 더 앞순서
	}
}
