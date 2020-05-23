#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> makeTable(string pattern) {
	int size = pattern.size();
	vector<int> table(size, 0);
	int j = 0;
	for (int i = 1; i < size; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j-1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}
vector<int> kmp(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	vector<int> v;
	int j = 0;
	for (int i = 1; i < parent.size(); i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				v.push_back(i - pattern.size() + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
	return v;
}
int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> result = makeTable(str);
	cout<< n - result[result.size() - 1];
	return 0;
}