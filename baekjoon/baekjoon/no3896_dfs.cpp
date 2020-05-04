#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main() {
	int n;
	cin >> n;
	string str;
	stack<char> s;
	int result=0;
	bool check = true;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int index = 0;
		while (index < str.length()) {
			char cur = str[index];
			if (s.size() == 0) {
				s.push(cur);
			}
			else {
				if (s.top() == cur) {
					s.pop();
				}
				else {
					s.push(cur);
				}
			}
			index++;
		}
		if (s.size() > 0) {
			while (!s.empty()) {
				s.pop();
			}
		}
		else {
			result++;
		}
	}
	cout << result;
	return 0;
}