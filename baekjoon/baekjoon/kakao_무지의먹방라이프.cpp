#include <string>
#include <vector>

#include<stdlib.h>
#include<time.h>

using namespace std;


long long solution(vector<int> food_times, long long k) {
	long long answer = -1;
	long long copyk = k;
	long long size = food_times.size();
	long long total, remove;
	bool check = false;

	while (k > size) {
		remove = k / size;
		k -= remove * size;
		total = 0;

		for (int i = 0; i < food_times.size(); i++) {
			if (check == false) {
				copyk -= food_times[i];
			}
			if (food_times[i] > 0) {
				food_times[i] -= remove;
				if (food_times[i] <= 0) {
					total += food_times[i];
					size--;
				}
			}
		}

		if (check == false && copyk >= 0) {
			return answer;
		}
		check = true;
		k -= total;
	}

	for (int i = 0; i < food_times.size(); i++) {
		if (food_times[i] > 0) {
			if (answer < 0) {
				answer = i + 1;
			}
			if (k == 0) {
				answer = i + 1;
				return answer;
			}
			k--;
		}
	}
	return answer;
}
int main() {
	vector<int> food_times;
	long long k = 12;
	food_times.push_back(3);
	food_times.push_back(1);
	food_times.push_back(1);
	food_times.push_back(1);
	food_times.push_back(2);
	food_times.push_back(4);
	food_times.push_back(3);

	printf("%d", solution(food_times, k));
	return 0;
}
