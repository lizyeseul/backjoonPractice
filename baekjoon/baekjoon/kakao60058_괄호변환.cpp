#include <string>
#include<iostream>
using namespace std;

bool isPerfect(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')	count++;
		else count--;

		if (count < 0) return false;
	}
	return true;
}

int balance(string str) {
	int index;
	int left=0, right = 0;
	for (index = 0; index < str.size(); index++) {
		if (str[index] == '(')	left++;
		else right++;
		if (left == right) {
			return index+1;
		}
	}
	return index;
}

string flip(string str) {
	string result = "";
	for (int index = 1; index < str.size()-1; index++) {
		if (str[index] == '(')	result+= ")";
		else result += "(";
	}
	return result;
}
string re(string a) {
	if (a.size() == 0)	return "";
	else if (a.size() == 2) return "()";


	int partition = balance(a);
	string u = a.substr(0, partition);
	string v = a.substr(partition, a.size());

	string result = "";
	if (isPerfect(u) == true) {
		result= u;
		result += re(v);
	}
	else {
		result = "(";
		result += re(v);
		result += ")";
		result += flip(u);
	}

	return result;
}
int main() {
	string p = "()))((()";
	string answer = "";

	if (answer.size() == 0) {
		//return answer;
	}
	
	//answer = re(p);
	

	cout << re(p);
	//return answer;
}