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

int uf[MAXN];
void uf_init() { forn(i,MAXN) uf[i]=i; }
int uf_find(int i) { return uf[i] = uf[i] == i ? i : uf_find(uf[i]); }
void uf_join(int i, int j) { uf[uf_find(i)] = uf_find(j); }

vector<int> g[MAXN];
int n,m,k;
int s, t;
int a[MAXN];
bool vis[MAXN];

bool connected(int s, int t) { return uf_find(s) == uf_find(t); }

void bfs(int cut) {
	// cerr << "========================\n";
	// db(cut);

	uf_init();
	memset(vis, 0, sizeof(vis));

	queue<pii> Q;

	Q.push({0, t});
	forn(i,k) Q.push({0, a[i]});

	while (!Q.empty()) {
		auto [d, u] = Q.front();
		// cerr << "*** ";
		// u+=1;
		// db(u);
		// u-=1;
		vis[u] = true;
		Q.pop();
		for (int v : g[u]) {
			if (d+1 <= cut) {
				uf_join(u,v);
				// cerr << "CONN " << u+1 << " " << v+1 << "\n";
			}
		}
		for (int v : g[u]) {
			if (d+1 <= cut) {
				if (vis[v]) continue;
				vis[v] = true;
				// cerr << "PUSH " << v+1 << " (dist " << d+1 << ", parent " << u + 1 << ")\n";
				Q.push({d+1, v});
			}
		}
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> m >> k;

	forn(i,k) { cin >> a[i]; --a[i]; }
	forn(i,m) { int u, v; cin >> u>> v; --u;--v; g[u].pb(v); g[v].pb(u); }

	cin >> s >> t;
	--s;--t;

	uf_init();
	forn(u,n) for(int v : g[u]) uf_join(u,v);
	if (!connected(s, t)) { cout << "-1\n"; return 0; }


	int lo = 0;
	int hi = n;
	while (hi-lo > 1) {
		int cut = (hi+lo)/2;
		bfs(cut);
		if (connected(s, t)) {
			// cerr << "REACHABLE\n";
			hi = cut;
		} else {
			// cerr << "NOT REACHABLE\n";
			lo = cut;
		}
	}


	bfs(lo);

	// forn(i,n) cerr << ' ' << i;
	// cerr << '\n';
	// forn(i,n) cerr << ' ' << (vis[i]?'#':'.');
	// cerr << '\n';

	forn(u,n) for(int v:g[u])
		if(vis[u] && vis[v]) uf_join(u, v);

	int ans = 2*lo + 1;
	ans += !connected(s,t);

	cout << ans << '\n';

    return 0;
}
