#include <stdio.h>
#include <math.h>

void main()
{
	int n;
	int a[1000], b[1000];
	int s = 0;
	scanf_s("%d", &n);

	//array a
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	//array b
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &b[i]);
	}

	/*
 5
 1 1 1 6 0
 2 7 8 3 1 -> 4(4)
 

 1 1 0 1 6
 */
	int min, max;
	int inA[1000], inB[1000];
	int indexA, indexB;

	for (int i = 0; i < n; i++) {
		min = 9999;
		max = -1;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < i + 1; k++) {//index array
				if (inB[k] == j)
					continue;

				if (min > b[j]) {
					min = b[j];
					indexB = j;
					printf("----------------------- b %d\n", indexB);
				}
			}

			for (int k = 0; k < i + 1; k++) {
				if (inA[k] == j) {
					continue;
				}
				if (max < a[j]) {
					max = a[j];
					indexA = j;
					printf("----------------------- a %d\n", indexA);
				}
			}
		}

		inA[i] = indexA;
		inB[i] = indexB;
		printf("%d\n", min);

		int temp = a[inA[i]];
		a[inA[i]] = a[inB[i]];
		a[inB[i]] = temp;

		printf("[a]\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	printf("\n[indexA]\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", inA[i]);
	}

	printf("\n[indexB]\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", inB[i]);
	}

}