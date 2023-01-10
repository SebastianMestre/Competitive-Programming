#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i = int(a); i < int(b); ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = int(n)-1; i >= int(a); --i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) cerr << #v " = "<<(v)<<'\n'
#define vecp(v) cerr << #v " = "; for(auto ee : v) cerr << ee << ' '; cerr << '\n'
#define nn cout << '\n'
#define sz(v) (int(v.size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define pp pop_back
#define fst first
#define snd second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll MAXN = 2e5 + 100;
const ll INF  = 1e18 + 100;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	forn(i,n) cin >> a[i];

	vector<int> towers;
	towers.reserve(n);
	forn(i,n) {

		int lo = -1;
		int hi = sz(towers);

		while (hi-lo > 1) {
			int mi = (lo+hi)/2;
			if (towers[mi] <= a[i]) {
				lo = mi;
			} else {
				hi = mi;
			}
		}

		if (hi == sz(towers)) {
			towers.pb(a[i]);
		} else {
			towers[hi] = a[i];
		}

	}

	cout << sz(towers) << '\n';
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t; cin >> t; forn(_,t)
		solve();

	return 0;
}
