#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		map<int, int> mp;
		mp[1] = 101;
		for (int i = 0; i < k; i++) {
			int u, v;
			cin >> u >> v;
			if (u == 1 || v == 1) {
				mp[u] = 101;
				mp[v] = 101;
				continue;
			}
			if (mp[u] == 101) {
				mp[v] = 101;
			} else if (mp[v] == 101) {
				mp[u] = 101;
			} else {
				mp[u] = -1;
				mp[v] = -1;
			}
		}
		for (auto& x : mp) {
			if (x.second == 101) {
				cout << x.first << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}