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
		sort(s.begin(), s.end());

		int x = 0, y = n - 1, step = 0;
		string ans;
		for (int i = n; i > 0; i--) {
			int gcd = __gcd(i, n);
			if (gcd % 2) {
				step++;
			}

			if (step % 2) {
				ans += s[x++];
			}
			else {
				ans += s[y--];
			}
		}

		reverse(ans.begin(), ans.end());

		cout << ans << '\n';
	}

	return 0;
}