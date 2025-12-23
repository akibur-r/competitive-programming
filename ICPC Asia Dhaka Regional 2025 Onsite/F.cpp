#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long int;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tt; cin >> tt;
	for (int tc = 0; tc < tt; tc++) {
		ll l, v, t, n;
		cin >> l >> v >> t >> n;

		for (ll i = 1; i <= n; i++) {
			ll x, y; cin >> x >> y;

			ll v_diff = abs(v - y);
			ll time = t - x;

			ll temp2 = (time * v_diff) / l;

			cout << temp2 + 1;
			if (i < n) cout << " ";
		}
		cout << '\n';
	}

	return 0;
}