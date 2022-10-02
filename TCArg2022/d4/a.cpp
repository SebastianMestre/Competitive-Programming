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

vector<int> g1[MAXN];
vector<int> g2[MAXN];

int color[MAXN];

int otro_color(int c) { return 3-c; }
void colorear(int u, int c) {
	color[u] = c;
	for (int v : g1[u]) {
		if (color[v]) continue;
		colorear(v, otro_color(c));
	}
}

struct edge {
	int tipo;
	int u, v;
};
vector<edge> edges;

bool visitado[MAXN];
bool camino[MAXN];
vector<int> orden;
bool hay_ciclos = false;
void toposort(int u) {
	visitado[u] = true;
	camino[u] = true;
	for (int v : g2[u]) {
		if (camino[v]) hay_ciclos = true;
		if (visitado[v]) continue;
		toposort(v);
	}
	camino[u] = false;
	orden.push_back(u);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n,m;
	cin >> n >> m;


	forn(i,m){
		int tipo, u, v;
		cin >> tipo >> u >> v;
		--u;--v;

		edges.push_back({tipo, u, v});
		g1[u].push_back(v);
		g1[v].push_back(u);
	}


	forn(u,n) if (!color[u]) {
		colorear(u, 1);
	}
	
	bool bien_coloreado = true;
	forn(u, n) {
		for (int v : g1[u]) {
			if (color[u] == color[v]) {
				bien_coloreado = false;
			}
		}
	}

	if (!bien_coloreado) {
		cout << "NO\n";
		return 0;
	}

	for (auto e : edges) {
		if (e.tipo == color[e.u]) {
			// cerr << e.u+1 << " ---> " << e.v+1 << "\n";
			g2[e.u].push_back(e.v);
		} else {
			// cerr << e.v+1 << " ---> " << e.u+1 << "\n";
			g2[e.v].push_back(e.u);
		}
	}

	forn(u,n) if (!visitado[u]) {
		toposort(u);
	}
	reverse(orden.begin(), orden.end());

	if (hay_ciclos) {
		cout << "NO\n";
		return 0;
	}

	vector<int> posicion(n);
	forn(i,n) posicion[orden[i]] = i;

	cout << "YES\n";
	forn(u,n){
		cout << (color[u]==1?'L':'R') << " " << posicion[u] << '\n';
	}

    return 0;
}

