#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
typedef long long ll;
void solve() {
	int q;
	cin >> q;
	forn(_, q) {
		ll k;
		cin >> k;
		k--;
		ll d = 1;
		ll pot = 1;
		while (true) {
			ll tot = d * 9 * pot;
			if (k < tot) break;
			k -= tot;
			d++;
			pot *= 10;
		}
		ll n_ix = k / d, d_ix = k % d;
		ll num = pot + n_ix;
		while (++d_ix != d) num /= 10;
		ll dig = num % 10;
		cout << dig << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
