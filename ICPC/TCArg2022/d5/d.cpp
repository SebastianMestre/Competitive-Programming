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

const ll MAXN = 1e3+100;
const ll MAXM = 3e4+100;
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

struct edge {
	int u, v; ll cost;
	int other(int w) const { return u ^ v ^ w; }
};

vector<int> g[MAXN];
edge edges[MAXM];
bool visited[MAXN];
bool is_tree_edge[MAXM];
bool is_tree_edge_old[MAXM];
bool is_bridge[MAXM];
int depth[MAXN];
int lo[MAXN];
int step[MAXN];

int banned_edge;

void dfs(int u) {
	visited[u] = true;
	for (int e : g[u]) if (e != banned_edge && e != step[u]) {
		int v = edges[e].other(u);
		if (!visited[v]) { // tree edge

			step[v] = e;
			depth[v] = depth[u] + 1;
			lo[v] = depth[v];
			is_tree_edge[e] = true;

			dfs(v);

			is_bridge[e] = lo[v] > depth[u];
			lo[u] = min(lo[u], lo[v]);

		} else { // back edge
			is_tree_edge[e] = false;

			is_bridge[e] = false;

			lo[u] = min(lo[u], depth[v]);
		}
	}
}

void run_dfs(int n, int src, int banned) {
	forn(u, n) visited[u] = false;
	step[src] = -1;
	depth[src] = 0;
	lo[src] = 0;
	banned_edge = banned;
	dfs(src);
}

void solve() {
	int n, m; cin >> n >> m;
	int s, t; cin >> s >> t; --s; --t;
	forn(e, m) {
		int u, v, w; cin >> u >> v >> w; --u; --v;
		edges[e] = {u, v, w};
		g[u].pb(e); g[v].pb(e);
	}
	// cerr << "DID INPUT\n";

	run_dfs(n, s, -1);
	if (!visited[t]) {
		cout << "0\n0\n";
		return;
	}

	// cerr << "DID DFS\n";

	forn(e, m) is_tree_edge_old[e] = is_tree_edge[e];

	pair<ll, vector<int>> ans = {INF, {}};

#if 0
	for (int pos = t; pos != s;) {
		int e = step[pos];
		if (is_bridge[e]) ans = min(ans, {edges[e].cost, {e}});
		pos = edges[e].other(pos);
	}
#endif

	forn(e, m) if (true || is_tree_edge_old[e]) {
		// cerr << "DOING EDGE " << e+1 << "\n";
		run_dfs(n, s, e);
		if (!visited[t]) {
			ans = min(ans, {edges[e].cost, {e}});
		} else {

			for (int pos = t; pos != s;) {
				int f = step[pos];
				// cerr << "-- EDGE " << f+1 << (is_bridge[f]?" (bridge)":"") << "\n";
				if (is_bridge[f]) ans = min(ans, {edges[f].cost + edges[e].cost, {f, e}});
				pos = edges[f].other(pos);
			}

		}
		// cerr << "DID EDGE " << e+1 << "\n";
	}

	if (ans.fst == INF) {
		cout << "-1\n";
	} else {
		cout << ans.fst << "\n";
		int const k = sz(ans.snd);
		cout << k << "\n";
		forn(i, k) cout << ans.snd[i]+1 << " \n"[i==k-1];
	}

}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	forn(_,t) solve();
}

