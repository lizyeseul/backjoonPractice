#include <string>
#include <vector>
#include <iostream>
using namespace std;

string numbers = "0123456789ABCDEF";

string game(int i, int n) {
	if (i / n == 0) {
		return numbers.substr(i % n, 1);
	}
	else {
		return game(i / n, n) + numbers[i % n];
	}
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string answer2 = "";
	int i = 0, cur = 0;
	while (answer2.length() < t) {
		answer += game(i++, n);
		while (cur < t && (p - 1) + m * (cur - 1) < answer2.length()) {
			answer2 += answer.substr((p - 1) + m * (cur++ - 1), 1);
		}
	}
	return answer2;
}

int main() {
	cout << solution(2, 4, 2, 1);
	return 0;
}