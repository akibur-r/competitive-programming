#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long int;

pair<ll, ll> f(ll x) {
	if (x == 1) return make_pair(0, 0);

	ll even = 0;
	while (x % 2 == 0) {
		even += 2;
		x /= 2;
	}

	if (x == 1) {
		return make_pair(0, even);
	}

	ll odd = 0;
	for (ll i = 3; i * i <= x; i += 2) {
		while (x % i == 0) {
			x /= i;
			odd += i;
		}
	}

	if (x != 1) {
		odd += x;
	}

	if (even == 0) {
		return make_pair(odd, 0);
	}

	return make_pair(odd, even);
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first - a.second < b.first - b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n, a, b; cin >> n >> a >> b;
		vector<pair<ll, ll>> v;
		ll x;
		for (int i = 0; i < n; i++) {
			cin >> x ;
			pair<ll, ll> p = f(x);
			v.push_back(p);
		}

		sort(v.begin(), v.end(), cmp);
		vector<ll> apref(n + 1), bpref(n + 1);

		for (int i = 0; i < n; i++) {
			apref[i + 1] = apref[i] + v[i].first;
			bpref[i + 1] = bpref[i] + v[i].second;
		}

		ll sum = 1e14;
		for (int i = a; i <= n - b; i++) {
			ll ev_even = apref[i];
			ll od_odd = bpref[n] - bpref[i];

			sum = min(sum, ev_even + od_odd);
		}
		cout << sum << '\n';
	}

	return 0;
}