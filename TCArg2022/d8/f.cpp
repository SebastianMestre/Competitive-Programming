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

const ll MAXN = 3e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

ll ft[MAXN];

void ft_update(int x0, ll val) {
	x0 += 5;
	for (int x = x0+1; x < MAXN; x += x&-x) {
		ft[x] += val;
	}
}

ll ft_query(int x0) {
	x0 += 5;
	ll result = 0;
	for (int x = x0+1; x > 0; x -= x&-x) {
		result += ft[x];
	}
	return result;
}


vector<int> g[MAXN];

int mi_left[MAXN];
int mi_right[MAXN];
int level[MAXN];

int dfscounter = 0;

void dfs(int u, int p) {
	mi_left[u] = dfscounter++;
	for (int v : g[u]) {
		if (v == p) continue;
		level[v] = level[u] + 1;
		dfs(v, u);
	}
	mi_right[u] = dfscounter;
}

struct Query { int x, y; ll val; };

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;
	forn(i,n-1) {
		int u,v;
		cin >> u >> v;
		--u;--v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(0, 0);

	vector<Query> queries;

	int q;
	cin >> q;
	forn(i,q) {
		int u; ll d; ll x;
		cin >> u >> d >> x;
		--u;

		int T = level[u];
		int B = min(level[u] + d + 1, ll(n+10));

		int L = mi_left[u];
		int R = mi_right[u];

		queries.pb({L, T,  x});
		queries.pb({L, B, -x});
		queries.pb({R, T, -x});
		queries.pb({R, B,  x});
	}

	sort(all(queries), [](Query a, Query b) {
		return make_pair(a.y, a.x) < make_pair(b.y, b.x);
	});

	vector<int> nodes(n);
	forn(u,n) nodes[u] = u;
	sort(all(nodes), [](int u, int v) {
		return level[u] < level[v];
	});

	int i = 0;
	vector<ll> ans(n);
	for (int u : nodes) {
		int X = mi_left[u];
		int Y = level[u];

		for (; i < queries.size() && queries[i].y <= Y; ++i) {
			auto Q = queries[i];
			ft_update(queries[i].x, queries[i].val);
		}
		ans[u] = ft_query(X);
	}

	auto sep = "";
	forn(u, n) {
		cout << exchange(sep, " ") << ans[u];
	}
	cout << '\n';
    
    return 0;
}
