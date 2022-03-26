#include <bits/stdc++.h>
using namespace std;

void perform_test() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int five = 0, ten = 0;
	int cnt5 = 0, cnt10 = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 10) {
			cnt10++;
			if(cnt5 > 0) {
				five++;
				cnt5 = 0;
			}
		} else {
			cnt5++;
			if(cnt10 > 0) {
				ten++;
				cnt10 = 0;
			}
		}
	}
	cout << min(five, ten) << "\n";
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
