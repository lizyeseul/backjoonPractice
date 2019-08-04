#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stack[10002], top =-1, pu[10001];

void push(int x);
int pop();

int main() {
	int n, command[10000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char com[10];
		scanf("%s", &com);
		if (strcmp(com, "push")==0) { 
			command[i] = 1; 
			n++;
		}
		else if (strcmp(com, "pop") == 0)	command[i] = 2;
		else if (strcmp(com, "size") == 0)	command[i] = 3;
		else if (strcmp(com, "empty") == 0)	command[i] = 4;
		else if (strcmp(com, "top") == 0)	command[i] = 5;
		else {
			pu[i] = atoi(com);
			command[i] = 6;
		}
	}

	for (int i = 0; i < n; i++) {
		int x;
		switch (command[i]) {
			case 1:
				x = pu[i+1];
				push(x);
				break;
			case 2:
				x = pop();
				printf("%d", x);
				if (i < n - 1)
					printf("\n");
				break;
			case 3:
				printf("%d", top + 1);
				if (i < n - 1)
					printf("\n");
				break;
			case 4:
				if (top == -1)
					printf("1");
				else
					printf("0");

				if (i < n - 1)
					printf("\n");
				break;
			case 5:
				if (top == -1)
					printf("-1");
				else
					printf("%d", stack[top]);

				if (i < n - 1)
					printf("\n");
				break;
			case 6:
				break;
		}
	}
	return 0;
}

int pop() {
	if (top == -1)
		return -1;
	else {
		int temp = stack[top];
		stack[top] = 0;
		top--;
		return temp;
	}
}

void push(int x) {
	top++;
	stack[top] = x;
}