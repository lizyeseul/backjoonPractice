#include <string>
#include <vector>
#include <iostream>
using namespace std;

char numbers[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
string game(int i, int n) {
	string result = "";
	int tmp;
	while (i / n != 0) {
		tmp = i % n;
		result = numbers[tmp] + result;
		i /= n;
	}
	return numbers[i%n] + result;
}

string solution(int n, int t, int m, int p) {
	int i = 0;
	string answer = game(i, n);
	int idx = p-1;
	string result = "";
	while (result.length() < t) {
		answer = game(i++, n);
		if (answer.length() <= idx) {
			idx -= answer.length();
			continue;
		}
		for (int cur = idx; cur < answer.length(); cur+=m) {
			result += answer[cur];
			if (result.length() == t) return result;
			idx += m;
		}
		idx -= answer.length();
	}
	return result;
}

int main() {
	cout << solution(16, 16, 2, 2);
	return 0;
}