#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) // cerr << #v << " = " << v << '\n';
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

const ll MAXN = 1e3+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int uf_rep[MAXN];
void uf_init() { forn(i,MAXN) uf_rep[i] = i; }
int uf_find(int i) {
	if (uf_rep[i] == i) return i;
	return uf_rep[i] = uf_find(uf_rep[i]);
}
void uf_join(int i, int j) {
	i = uf_find(i); j = uf_find(j);
	uf_rep[i] = j;
}


ll x[MAXN];
ll y[MAXN];

struct Edge {
	int u, v;
	ll w;
};

ll c1[MAXN];
ll c2[MAXN];

ll temp[MAXN];

struct Hedge {
	int v;
	ll w;
};

vector<Hedge> g[MAXN];

void dfs(int u, int p) {
	for (auto e : g[u]) {
		if (e.v == p) continue;
		temp[e.v] = max(e.w, temp[u]);
		dfs(e.v, u);
	}
}

ll dist_cuad(int u, int v){ 
	ll dx = x[u] - x[v];
	ll dy = y[u] - y[v];
	return dx*dx + dy*dy;
}

ll matriz[MAXN][MAXN];

ll cuad(ll x) { return x * x; }

int main(){
    freopen("froggy.in", "r", stdin);
    freopen("froggy.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	ll w;
	cin >> w >> n;


	db(n);
	db(w);

	forn(i,n) {
		cin >> x[i] >> y[i];
	}

	x[n] = 0;
	x[n+1] = w;

	forn(i,n) {
		forn(j,n) {
			matriz[i][j] = dist_cuad(i,j);
		}
		matriz[n][i]   = matriz[i][n]   = cuad(x[i]);
		matriz[n+1][i] = matriz[i][n+1] = cuad(w-x[i]);
	}
	matriz[n][n+1] = matriz[n+1][n] = cuad(w);

	vector<Edge> edges;
	forn(i,n+2) {
		forr(j,i+1,n+2) {
			ll w = matriz[i][j];
			edges.pb({i, j, w});
		}
	}

	sort(all(edges), [](Edge e, Edge f) {
		return e.w < f.w;
	});

	uf_init();

	forn(i, edges.size()) {
		int u = edges[i].u;
		int v = edges[i].v;
		ll  w = edges[i].w;
		if (uf_find(u) == uf_find(v)) continue;
		uf_join(u, v);
		g[u].pb({v,w});
		g[v].pb({u,w});
	}

	memset(temp, 0, sizeof(temp));
	dfs(n, n);
	memcpy(c1, temp, sizeof(temp));

	memset(temp, 0, sizeof(temp));
	dfs(n+1, n+1);
	memcpy(c2, temp, sizeof(temp));

	int ia = -1;
	int ja = -1;
	ll answer = matriz[n][n+1] * 4;
	forn(i, n+2) {
		forn(j, n+2) {

			ll w = matriz[i][j];
			ll res = max({c1[i]*4, w, c2[j]*4});
			db(w);
			db(res);

			if (ia == -1 || res <= answer) {
				ia = i;
				ja = j;
				answer = res;
			}
		}
	}

	db(ia);
	db(ja);

	auto midy = [&](int i, int j) -> ld {
		if (j < i) swap(i, j);
		if (i == n && j == n+1) return 0;
		if (j ==   n) return y[i];
		if (j == n+1) return y[i];
		return ((ld)y[ia] + (ld)y[ja])/2;
	};

	ld xp = ((ld)x[ia] + (ld)x[ja])/2;
	ld yp = midy(ia, ja);
	cout << fixed << setprecision(4);
	cout << xp << ' ' << yp << '\n';

	return 0;
}
