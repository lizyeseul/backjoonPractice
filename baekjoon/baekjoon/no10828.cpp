#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;

	stack<int> s;
	string command;
	while (n > 0) {
		cin >> command;
		if (command.compare("push") == 0) {
			int num;
			cin >> num;
			s.push(num);
		} else if (command.compare("pop") == 0) {
			if (s.empty() == false) {
				cout << s.top() << '\n';
				s.pop();
			}
			else {
				cout << "-1\n";
			}
		} else if (command.compare("size") == 0) {
			cout << s.size() << '\n';
		} else if (command.compare("empty") == 0) {
			cout << s.empty() << '\n';
		} else if (command.compare("top") == 0) {
			if (s.empty() == false) {
				cout << s.top() << '\n';
			}
			else {
				cout << "-1\n";
			}
		}
		n--;
	}

	return 0;
}