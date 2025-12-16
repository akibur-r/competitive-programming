/*
Code by: akibur_r
IIUC Inter University Programming Contest 2025
https://toph.co/c/inter-university-iiuc-tech-fest-2025
*/

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long int;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int lg = log2(n);

	int temp = (1 << (lg + 1)) - 1;

	if (n == 1) {
		cout << "0\n";
	}
	else if (a.back() == n && n == temp) {
		// cout << "H";
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}