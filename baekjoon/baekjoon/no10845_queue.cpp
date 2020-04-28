#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;

	queue <int> q;
	string command;
	while (n > 0) {
		cin >> command;
		if (command.compare("push") == 0) {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (command.compare("pop") == 0) {
			if (q.empty() == false) {
				cout << q.front() << '\n';
				q.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command.compare("size") == 0) {
			cout << q.size() << '\n';
		}
		else if (command.compare("empty") == 0) {
			cout << q.empty() << '\n';
		}
		else if (command.compare("front") == 0) {
			if (q.empty() == false) {
				cout << q.front() << '\n';
			}
			else {
				cout << "-1\n";
			}
		}
		else if (command.compare("back") == 0) {
			if (q.empty() == false) {
				cout << q.back() << '\n';
			}
			else {
				cout << "-1\n";
			}
		}
		n--;
	}

	return 0;
}