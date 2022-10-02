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

int t[30][MAXN];

int get(int u, int d) {
	int k = 0;
	while (d) {
		if (d&1) u = t[k][u];
		d >>= 1;
		k += 1;
	}
	return u;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n, q;
	cin >> n >> q;
	forn(u,n) cin >> t[0][u];
	forn(u,n) t[0][u]--;

	forn(k,30-1) forn(u,n) t[k+1][u] = t[k][t[k][u]];

	forn(i,q) {
		int u, k; cin >> u >> k; u--;
		cout << get(u, k)+1 << '\n';
	}

    return 0;
}
