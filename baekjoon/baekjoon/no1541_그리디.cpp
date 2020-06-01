#include<iostream>
#include<string>
using namespace std;
int main() {
	string str, num="";
	cin >> str;
	int total=0;
	bool minus = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+') {
			if (minus==false) {
				total += stoi(num);
			}
			else {
				total -= stoi(num);
			}
			num = "";
		}
		else if (str[i] == '-') {
			if (minus == false) {
				total += stoi(num);
				minus = true;
			}
			else {
				total -= stoi(num);
			}
			num = "";
		}
		else { num += str[i]; }
	}
	if (minus == false) {
		total += stoi(num);
	}
	else {
		total -= stoi(num);
	}
	cout << total<<endl;
	return 0;
}