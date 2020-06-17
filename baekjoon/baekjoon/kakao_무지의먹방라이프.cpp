#include <string>
#include <vector>
#include<algorithm>

using namespace std;


long long solution2(vector<int> food_times, long long k) {
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

using ll = long long;

bool sort_by_idx(pair<ll, int> a, pair<ll, int> b) {
	return a.second < b.second;
}
int solution(vector<int> food_times, ll k) {
	vector<pair<ll, int>> times;
	for (int i = 0; i < food_times.size(); i++) {
		times.push_back({ food_times[i], i + 1 });
	}
	sort(times.begin(), times.end());
	printf("\n====================\n");
	for (int j = 0; j < times.size(); j++) {
		printf("%lld", times[j].first);
		printf(":%d - ", times[j].second);
	}
	printf("\n====================\n");
	int n = times.size();
	int i = 0;
	for (; i < n; i++) {
		ll diff = (i == 0 ? times[0].first : times[i].first - times[i - 1].first);
		ll total = diff * (n - i);
		if (k - total < 0) break;
		else k -= total;
	}
	if (i == n) return -1;
	k %= (n - i);
	sort(times.begin() + i, times.end(), sort_by_idx);
	printf("\n====================\n");
	for (int j = 0; j < times.size(); j++) {
		printf("%lld", times[j].first);
		printf(":%d - ", times[j].second);
	}
	printf("\n====================\n");
	return times[i + k].second;
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
