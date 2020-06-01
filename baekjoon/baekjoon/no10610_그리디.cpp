#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
bool compare(int a, int b) { return a > b; }
int main() {
	vector<int> v;
	char c = getchar();
	int total = 0;
	bool check = false;
	while (c != '\n') {
		v.push_back(c - 48);
		total += c - 48;
		if (c - 48 == 0) {
			check = true;
		}
		c = getchar();
	}
	
	if (check == true && total % 3 == 0) {
		sort(v.begin(), v.end(), compare);
		for (int i = 0; i < v.size(); i++) {
			printf("%d", v[i]);
		}
	}
	else {
		printf("-1");
	}

	return 0;
}