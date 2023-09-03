#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define fore(e,c) for(const auto &e : (c))
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define nn cout<<'\n'
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAXN = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

template<typename T>
ostream& operator<<(ostream& o, vector<T> const& v) {
	o << "[ ";
	for (auto const& x : v)
		o << x << " ";
	return o << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream& o, pair<T, U> const& p) {
	return o
	<< "("
	<< p.fst
	<< ","
	<< " "
	<< p.snd
	<< ")"
	;
}

vector<int> g[MAXN];
int h[MAXN];
bool vis[MAXN];

vector<int> comp;

void dfs(int u) {
	vis[u] = true;
	comp.pb(u);
	for (int v : g[u]) if (!vis[v]) {
		dfs(v);
	}
}

struct mset {
	map<ll,int> m;
	void add(ll x) { m[x]++; }
	void rem(ll x) { if (--m[x] == 0) m.erase(x); }
	ll max() { return m.empty() ? LLONG_MIN : m.rbegin()->fst; }
};

void solve() {
	int n, m, k; cin >> n >> m >> k;

	forn(i, n) g[i].clear();
	fill(vis, vis+n, false);

	forn(i, n) cin >> h[i];
	forn(i, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].pb(v);
		g[v].pb(u);
	}
 
 	vector<pll> periods;
	vector<ll> dp(n, 0);
	dforn(u, n) {
		for (int v : g[u]) if (u<v) {
			dp[u] = max(dp[u], dp[v] + ((h[v]-h[u])%k+k)%k);
		}
		periods.pb({h[u], h[u]+dp[u]});
	}

	{
		sort(all(periods));
		vector<pll> clean;
		for (auto p : periods) {
			if (!clean.empty() && clean.back().fst == p.fst) clean.back() = p;
			else clean.pb(p);
		}
		periods = clean;
	}

	mset ends;
	for (auto p : periods) {
		ends.add(p.snd);
	}

	ll ans = LLONG_MAX;
	for (auto p : periods) {
		ans = min(ans, ends.max() - p.fst);
		ends.rem(p.snd);
		ends.add(p.snd + k);
	}
	cout << ans << "\n";
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;
	forn(_,t) solve();
}
