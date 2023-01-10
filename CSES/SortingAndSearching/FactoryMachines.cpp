#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
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
	int n, t;
	cin >> n >> t;

	vector<ll> k(n);
	forn(i,n) cin >> k[i];

	ll lo = 0;                        // INVARIANTE: puedo(lo) siempre es false
	ll hi = *min_element(all(k)) * t; // INVARIANTE: puedo(hi) siempre es true

	auto puedo = [&](ll time) {
		ll productos = 0;
		forn(i,n) productos += time / k[i];
		return productos >= t;
	};

	while (hi-lo > 1) {
		ll mi = (hi+lo)/2;
		if (puedo(mi)) { // puedo(mi)==true.
			// Para mantener la invariante puedo(hi)==true, pongo hi=mi
			hi = mi;
		} else { // puedo(mi)==false.
			// Para mantener la invariante puedo(lo)==false, pongo lo=mi
			lo = mi;
		}
	}

	cout << hi << '\n';
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	solve();
    
    return 0;
}
