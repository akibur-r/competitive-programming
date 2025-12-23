#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long int;

ll sz;
int x, y, z;

struct DSU {
	vector<int> par, Size, Rank;

	DSU(int n) {
		par.resize(n + 1);
		Size.assign(n + 1, 1);
		for (int i = 0; i <= n; i++) par[i] = i;
	}

	int find(int u) {
		if (u == par[u]) return u;
		return par[u] = find(par[u]);
	}

	bool unite(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		if (Size[u] < Size[v]) swap(u, v);
		par[v] = u;
		Size[u] += Size[v];
		return true;
	}

	int query(int u) {
		u = find(u);
		return Size[u];
	}
};

bool valid(int n) {
	if (n >= 0 && n < sz) return 1;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		cin >> x >> y >> z;
		sz = x * y * z;


		string s(sz + 1, '#');
		DSU ds(sz);

		int t = 0;
		for (int i = 1; i <= z; i++) {
			for (int j = 1; j <= x; j++) {
				for (int k = 1; k <= y; k++) {
					cin >> s[t];
					t++;
				}
			}
		}

		t = 0;
		int prev_plane = x * y;
		for (int i = 0; i < z; i++) {
			for (int j = 0; j < x; j++) {
				for (int k = 0; k < y; k++) {
					// cout << t - x << ' ';
					if (s[t] == '#') {
						t++;
						continue;
					}

					int up = t - prev_plane;
					int down = t + prev_plane;

					if (valid(up) && s[up] == '.') {
						ds.unite(t, up);
					}
					if (valid(down) && s[down] == '.') {
						ds.unite(t, down);
					}

					if (j - 1 >= 0 && valid(t - y) && s[t - y] == '.') {
						ds.unite(t, t - y);
					}

					if (k - 1 >= 0 && valid(t - 1) && s[t - 1] == '.') {
						ds.unite(t, t - 1);
					}

					t++;
				}
			}
		}

		ll ans = 0;
		for (int i = 0; i < prev_plane; i++) {
			set<int> se;
			ll sum = 0;

			for (int j = 0; j < sz; j += prev_plane) {
				if (s[i + j] == '#') continue;
				int u = ds.find(i + j);

				if (!se.count(u)) {
					sum += ds.query(u);
					se.insert(u);
				}

			}
			ans = max(ans, sum);
		}

		cout << ans << '\n';
	}

	return 0;
}