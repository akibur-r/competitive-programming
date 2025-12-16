/*
Code by: akibur_r
IIUC Inter University Programming Contest 2025
https://toph.co/c/inter-university-iiuc-tech-fest-2025
*/

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long int;

const int N = 2e5 + 100;
int vis[N];
set<int> primes;

void make_sieve() {
	for (int i = 2; i < N; i++) {
		if (vis[i]) continue;

		for (int j = i * 2; j < N; j += i) {
			vis[j]++;
		}

	}

	for (int i = 2; i < N; i++) {
		if (!vis[i]) {
			primes.insert(i);
		}
	}
}

vector<int> get_divisors(int n) {
	vector<int> d;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			d.push_back(i);
			if (n / i != i) d.push_back(n / i);
		}
	}

	return d;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	make_sieve();
	// cout << primes.size() << "\n\n";

	int tt; cin >> tt;
	while (tt--) {
		int n, x; cin >> n;
		multiset<int> ms;
		set<int> se;
		for (int i = 0; i < n; i++) {
			cin >> x;
			ms.insert(x);
			se.insert(x);
		}

		ll cnt = 0;

		for (auto xx : se) {
			vector<int> div = get_divisors(xx);
			// cout << xx << ": ";

			for (auto d : div) {
				// cout << d << ' ';
				if (se.count(d)) {
					int temp = xx / d;
					int root = sqrt(temp);

					if (root * root == temp && primes.count(root)) {
						int tempcnt = ms.count(d);
						int tempcnt2 = ms.count(xx);

						cnt += 1ll * tempcnt * tempcnt2;
					}
				}
				// cout << d << ' ';
			}

			// cout << '\n';
		}

		cout << cnt << "\n";


	}

	return 0;
}