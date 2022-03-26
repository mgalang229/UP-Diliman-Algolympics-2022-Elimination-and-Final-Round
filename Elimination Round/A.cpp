#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<string, int> mp;
	map<string, int> res;
	for (int i = 0; i < 2 * n; i++) {
		string name;
		int time;
		cin >> name >> time;
 		mp[name] = time - mp[name];
 		res[name] = 1;
		if (mp[name] > 216000) {
			res[name] = -1;
		}
	}
	for (auto& e : res) {
		cout << e.first << " ";
		if (e.second == 1) {
			cout << "has reasonable work hours!";
		} else {
			cout << "overworked their PR0xF!";
		}
		cout << '\n';
	}
	return 0;
}