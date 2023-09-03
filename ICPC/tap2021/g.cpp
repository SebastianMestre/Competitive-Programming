#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i = 0; i <int(n);++i)
#define forr(i,s,n) for(int i = s; i <int(n);++i)
#define fore(e,v) for(const auto& e : v)

using ll = long long;
vector<ll> fibos;
vector<ll> facs;

bool factorizar(ll n, int i) {
	if (i < 0) return false;
	if (n == 1) return true;

	if (n % fibos[i] != 0)
		return factorizar(n, i-1);

	facs.push_back(i);
	if (factorizar(n / fibos[i], i))
		return true;
	facs.pop_back();

	return factorizar(n, i-1);
}

void solve() {
	ll n; cin >> n;

	 fibos.reserve(80);

	ll a = 1, b = 1;
	forn (i, 80) {
		ll c = a+b;
		a = b;
		b = c;
		fibos.push_back(c);
	}

	if (!factorizar(n, fibos.size()-1)) {
		cout << "IMPOSSIBLE\n";
	} else {
		sort(facs.rbegin(), facs.rend());
		for (auto j : facs) {
			forn(i, j+1) cout << 'A';
			cout << 'B';
		}
		cout << '\n';
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}
