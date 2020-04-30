#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	int count;
	bool result = true;
	while (n > 0) {
		count = 0;
		result = true;
		string ps;
		cin >> ps;
		for (int i = 0; i < ps.length(); i++) {
			if (ps[i] == '(') {
				count++;
			} else if (ps[i] == ')' && count > 0) {
				count--;
			}
			else {
				result = false;
			}
		}
		if (result == false || count > 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
		n--;
	}
	return 0;
}