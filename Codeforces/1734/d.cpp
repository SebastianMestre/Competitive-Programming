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

vector<pll> grupos(vector<int> a) {
	ll s = 0;
	ll ms = 0;
	vector<pll> result;
	forn(i,sz(a)) {
		s += a[i];
		ms = min(ms, s);
		if (s >= 0 || i+1 == sz(a)) {
			result.pb({s, ms});
			s = 0;
		}
	}
	return result;
}

void solve() {
	int n, k;
	cin >> n >> k;
	k--;

	vector<int> a(k);
	vector<int> b(n-k-1);

	ll vida;

	forn(i,k) cin >> a[i];
	cin >> vida;
	forn(i,n-k-1) cin >> b[i];

	reverse(all(a));

	auto ga = grupos(a);
	auto gb = grupos(b);

	int i = 0;
	int j = 0;

	while (i < sz(ga) && j < sz(gb)) {
		     if (-ga[i].snd <= vida) { vida += ga[i].fst; i++; }
		else if (-gb[j].snd <= vida) { vida += gb[j].fst; j++; }
		else break;
	}

	if (i == sz(ga) || j == sz(gb)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int t; cin >> t;
	forn(asdasd,t) solve();

    return 0;
}
