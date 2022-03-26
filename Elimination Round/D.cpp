#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int r, c;
		cin >> r >> c;
		vector<vector<char>> a(r, vector<char>(c));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> a[i][j];
			}
		}
		vector<tuple<char, int, int>> vec;
		tuple<char, int, int> cur;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] != '.') {
					if (a[i][j] == '*') {
						cur = make_tuple(a[i][j], i, j);
					} else {	
						vec.emplace_back(a[i][j], i, j);
					}
				}
			}
		}
		int len = vec.size();
		auto GetDistance = [](const tuple<char, int, int>& p1, const tuple<char, int, int>& p2) {
			int x_dist = abs(get<1>(p1) - get<1>(p2));
			int y_dist = abs(get<2>(p1) - get<2>(p2));
			return x_dist + y_dist;
		};
		sort(vec.begin(), vec.end(), [](const tuple<char, int, int>& x, const tuple<char, int, int>& y) {
			return get<0>(x) < get<0>(y);
		});
		vector<tuple<char, int, int>> res;
		for (int i = 0; i < len; i++) {
			if (isupper(get<0>(vec[i]))) {
				res.push_back(vec[i]);
				for (int j = i + 1; j < len; j++) {
					if (tolower(get<0>(vec[i])) == get<0>(vec[j])) {
						res.push_back(vec[j]);
						break;
					}
				}
			} else {
				break;
			}
		}
		long long ans = GetDistance(cur, res[0]);
		for (int i = 0; i + 1 < (int) res.size(); i++) {
			ans += GetDistance(res[i], res[i + 1]);
		}
		cout << ans << '\n';
	}
	return 0;
}