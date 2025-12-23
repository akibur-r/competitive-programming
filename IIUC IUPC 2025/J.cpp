#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long int;

const int N = 1e6 + 100;
vector<int> divi(N), a(N);
vector<int> pos(N);

void make_sieve() {
	for (int i = 1; i < N; i++) {
		a[i] = i;
	}

	for (int i = 2; i < N; i++) {
		for (int j = i; j < N; j += i) {
			if (a[j] % i == 0) {
				divi[j]++;
				a[j] /= i;
			}
		}
	}

	for (int i = 0; i < 13; i++) pos[i] = i;

	int curr = 12, mx = 12;
	for (int i = 13; i < N; i++) {
		if (divi[i] >= 3) curr++;
		else curr = max(0, curr - 1);

		mx = max(mx, curr);

		pos[i] = mx;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	make_sieve();

	int tt; cin >> tt;
	while (tt--) {
		int d, t; cin >> d >> t;

		if (pos[t] >= d) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}