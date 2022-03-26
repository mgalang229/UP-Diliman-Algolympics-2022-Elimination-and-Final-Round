#include <bits/stdc++.h>
using namespace std;

void perform_test() {
	int n;
	cin >> n;
	vector<int> p(n);
	int sz = INT_MIN;
	for(int i = 0; i < n; i++) {
		cin >> p[i];
		sz = max(sz, p[i]);
	}
	//3 secs -> up/down 1 floor
	//3 secs per person -> leave the elevator
	vector<int> counter(sz + 1, 0);
	for(int i = 0; i < n; i++) {
		counter[p[i]]++;
	}
	long long ans = 0;
	int prev = 1;
	for(int i = 0; i < sz + 1; i++) {
		if(counter[i] > 0 && i > 1) {
			//cout << i << " " << prev << "\n";
			//cout << 3 * (i - prev) << " " << 3 * counter[i] << "\n";
			ans += (3 * (i - prev));
			ans += (3 * counter[i]);
			prev = i;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}
