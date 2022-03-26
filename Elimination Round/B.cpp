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
		bool checker = true;
		for (int i = 0; i < r; i++) {
			bool temp = false;
			for (int j = 0; j < c; j++) {
				temp |= (a[i][j] == '.');
			}
			checker &= temp;
		}
		cout << (checker ? "DIPLOMACY!" : "FIREWORKS!") << '\n';
	}
	return 0;
}