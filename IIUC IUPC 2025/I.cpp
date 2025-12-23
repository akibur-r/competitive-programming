#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long int;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		string s; cin >> s;
		int m; cin >> m;
		for (int i = 0; i < n; i++) {
			int req = 'z' - s[i] + 1;

			if (req <= m && s[i] != 'a') {
				s[i] = 'a';
				m -= req;
			}
		}

		m %= 26;

		int req = 'z' - s[n - 1];
		if (m <= req) {
			s[n - 1] = m + s[n - 1];
		}
		else {
			int inc = m - req;
			s[n - 1] = 'a' + inc - 1;
		}

		cout << s << '\n';
	}

	return 0;
}