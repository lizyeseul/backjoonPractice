#include<stdio.h>
#include<algorithm>

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };
using namespace std;
void heapsort() {
	//赛 积己
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) swap(heap[root], heap[c]);
			c = root;
		} while (c != 0);
	}

	//赛 馆汗
	for (int i = number - 1; i >= 0; i--) {
		swap(heap[0], heap[i]);
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			if (c < i - 1 && heap[c] < heap[c + 1]) c++;
			if (c < i && heap[root] < heap[c])	swap(heap[root], heap[c]);
			root = c;
		} while (c < i);
	}
}
int main() {
	heapsort();
	for (int i = 0; i < number; i++) printf("%d ", heap[i]); printf("\n");
	return 0;
}