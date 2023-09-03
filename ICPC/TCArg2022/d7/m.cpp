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

auto _seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rnd((unsigned)_seed);
mt19937_64 rnd64((ull)_seed);

const ll MAXN = 2e5+100;
const ll MAXM = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int uf_rep[MAXN];
bool uf_ciclo[MAXN];
void uf_init() { forn(i,MAXN) uf_rep[i] = i; }
int uf_find(int i) {
	if (uf_rep[i] == i) return i;
	return uf_rep[i] = uf_find(uf_rep[i]);
}
void uf_join(int i, int j) {
	i = uf_find(i); j = uf_find(j);
	uf_rep[i] = j;
	uf_ciclo[j] = uf_ciclo[j] || uf_ciclo[i];
}

struct Edge {
	int u, v;
	ll w;
};

int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	vector<Edge> edges;

	int n, m;
	cin >> n >> m;
	forn(i,m) {
		int u, v; ll w;
		cin >> u >> v >> w;
		--u; --v;
		edges.pb({u, v, w});
	}

	uf_init();
	
	sort(all(edges), [](Edge a, Edge b){
		return a.w > b.w;
	});

	ll result = 0;

	forn(i, edges.size()) {
		int u = edges[i].u;
		int v = edges[i].v;
		ll  w = edges[i].w;

		int ru = uf_find(u);
		int rv = uf_find(v);
		if (ru == rv) {
			if (!uf_ciclo[ru]) {
				result += w;
				uf_ciclo[ru] = true;
			}
			continue;
		} else {
			if (!uf_ciclo[ru] || !uf_ciclo[rv]) {
				result += w;
				uf_join(ru, rv);
			}
		}
	}

	cout << result << '\n';

    return 0;
}
