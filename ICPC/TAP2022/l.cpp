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

vector<pii> g[MAXN];
vector<int> t[MAXN];

int color[MAXN];
int total[MAXN];

unordered_map<int,int> hist[MAXN];
ll boring[MAXN];

ll ans[MAXN];

int n;

inline ll cuenta(int c, int k) {
	return ll(k) * ll(total[c]-k);
}

void dfs(int u, int parent, int edge) {
	for (auto [v, id] : g[u]) {
		if (v == parent) continue;
		dfs(v, u, id);

		if (sz(hist[u]) < sz(hist[v])) {
			swap(boring[u], boring[v]);
			swap(hist[u], hist[v]);
		}

		for (auto [c, k] : hist[v]) {
			int& res = hist[u][c];
			boring[u] -= cuenta(c, res);
			res += k;
			boring[u] += cuenta(c, res);
		}
	}

	if (u == 0) return;
	ans[edge] = boring[u];
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n;

	forn(u,n) cin >> color[u];

	forn(id, n-1) {
		int u,v; cin >> u >> v; --u; --v;
		g[u].pb({v,id}); g[v].pb({u,id});
	}

	forn(u,n) total[color[u]] += 1;
	forn(u,n) hist[u][color[u]] = 1;
	forn(u,n) boring[u] = cuenta(color[u], 1);

	dfs(0, -1, -1);

	forn(id, n-1) cout << ans[id] << (id==n-2?"\n":" ");
    
    return 0;
}
