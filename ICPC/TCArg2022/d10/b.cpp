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

const ll MAXN = 1e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

const int BITS = 30;

bool vis[MAXN];
int hist0[BITS];
int hist1[BITS];
bool coloreable = true;
int val[MAXN];
struct Edge {
	int v, w;
};

vector<Edge> g[MAXN];

void dfs(int u) {
	vis[u] = true;
	forn(i, BITS) {
		if (val[u] & (1 << i)) {
			hist1[i] += 1;
		} else {
			hist0[i] += 1;
		}
	}
	for (auto e : g[u]) {
		if (vis[e.v]) {
			if ((val[u] ^ val[e.v]) != e.w) {
				coloreable = false;
			}
			continue;
		}
		val[e.v] = val[u] ^ e.w;
		dfs(e.v);
	}
}

ll run_dfs(int u) {
	memset(hist0, 0, sizeof(hist0));
	memset(hist1, 0, sizeof(hist1));
	dfs(u);

	ll best = 0;
	forn(i,BITS){
		best += (1ll<<i) * (ll)min(hist1[i], hist0[i]);
	}
	return best;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


	int n, m;
	cin >> n >> m;


	forn(i,m){
		int u,v,w;
		cin >> u >> v >> w;
		--u;--v;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}

	ll sumatotal = 0;
	forn(u,n){
		if (vis[u]) continue;
		sumatotal += run_dfs(u);
		if (!coloreable) {
			cout << "-1\n";
			return 0;
		}
	}


	cout << sumatotal << '\n';

    return 0;
}
