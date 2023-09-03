#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=(a);--i)
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

struct edge {
	int v, c;
};

void mejorar(ll& tgt, ll upd) {
	if (tgt == -1 || tgt > upd)
		tgt = upd;
}

ll rundp(vector<vector<edge>> const& fwd, int n, int k) {
	vector<vector<ll>> dp(n);

	forn (u, n) dp[u].resize(k+1, -1);
	forn (u, n) dp[u][0] = 0;

	forr (j, 1, k+1) {
		forn (u, n) {
			for (auto [v, c] : fwd[u]) {
				mejorar(dp[u][j], dp[v][j-1] + c);
			}
		}
	}

	ll result = -1;
	forn (u, n) {
		mejorar(result, dp[u][k]);
	}

	return result;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	int m;
	cin >> m;

	vector<vector<edge>> fwd(n);
	vector<vector<edge>> bwd(n);

	forn(i,m) {
		int u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		if (u < v) {
			fwd[u].push_back({v, c});
		} else {
			bwd[u].push_back({v, c});
		}
	}

	ll res = -1;
	mejorar(res, rundp(fwd,n,k));
	mejorar(res, rundp(bwd,n,k));

	cout << res << '\n';

}




//___________________________

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
