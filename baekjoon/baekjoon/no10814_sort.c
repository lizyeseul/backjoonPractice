#include<stdio.h>
#include<string.h>
struct member {
	int age;
	char name[101];
};
int sorted[200][100000] = { 0, };
int findIndex(int n);
int main() {
	int n;
	scanf("%d", &n);
	
	struct member m[100000];
	for (int i = 0; i < n; i++) {
		int age;
		scanf("%d%s", &age, &m[i].name);
		m[i].age = age;
		sorted[age][findIndex(age)] = i+1;
	}

	for (int i = 0; i < 200; i++) {
		int index = 0;
		while (sorted[i][index] != 0) {
			int next = sorted[i][index]-1;
			printf("%d %s\n", m[next].age, m[next].name);
			index++;
		}
	}
	return 0;
}
int findIndex(int n) {
	int index = 0;
	while (sorted[n][index] != 0) {
		index++;
	}
	return index;
}
