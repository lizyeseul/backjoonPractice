#include<stdio.h>
#include<stack>
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, k;
	stack<char> s;
	scanf("%d%d", &n, &k);

	int index = 0;
	char next = getchar();
	next = getchar();
	while (next != '\n') {
		while (!s.empty()) {
			if (s.top() < next && k > 0) {
				s.pop();
				k--;
			}
			else {
				break;
			}
		}
		s.push(next);
		index++;
		next = getchar();
	}
	while (k-- > 0 && !s.empty()) {
		s.pop();
	}
	int size = s.size();
	stack<char> temp;
	for (int i = 0; i < size; i++) {
		temp.push(s.top());
		s.pop();
	}
	for (int i = 0; i < size; i++) {
		printf("%c", temp.top());
		temp.pop();
	}
	return 0;
}