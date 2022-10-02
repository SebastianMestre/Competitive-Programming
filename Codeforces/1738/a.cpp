#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define vecp(v) cerr<<#v<<" = "; for(auto ee:v)cerr<<ee<<' '; cerr<<'\n'
#define nn cout<<'\n'
#define sz(v) (int(v.size()))
#define all(v) v.begin(), v.end()
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

const ll MAXN = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

void solve() {
	int n; cin >> n;

	vector<int> type(n);
	forn(i,n) cin >> type[i];

	vector<int> dmg(n);
	forn(i,n) cin >> dmg[i];

	vector<int> t1; vector<int> t0;
	forn(i,n) (type[i]?t1:t0).pb(dmg[i]);

	sort(all(t0)); reverse(all(t0));
	sort(all(t1)); reverse(all(t1));

	ll best = 0;

	auto cpm = [](vector<int>& a, vector<int>& b) -> ll {
		int i = 0; int j = 0;

		if (a.empty()) return 0ll;

		ll res = a.back();

		int n = sz(a)-1;
		int m = sz(b);

		while (1){
			if (j >= m) break;
			res += 2*b[j++];
			if (i >= n) break;
			res += 2*a[i++];
		}

		while (i < n) res += a[i++];
		while (j < m) res += b[j++];

		return res;
	};

	best = max(best, cpm(t0, t1));
	best = max(best, cpm(t1, t0));

	cout << best << '\n';
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t; cin >> t;
	forn(_,t) solve();
    
    return 0;
}
