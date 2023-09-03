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
#define RAYA cerr<<"==================================================\n";

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll MAXN = 1<<19;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int const UF = 1<<20;
int uf[UF];
void uf_init() { forn(i,UF) uf[i] = i; }
int uf_find(int i) { return uf[i] == i ? i : uf[i] = uf_find(uf[i]); }
void uf_join(int i, int j) { uf[uf_find(i)] = uf_find(j); }
bool uf_conn(int i, int j) { return uf_find(i) == uf_find(j); }

int neg(int u) { return u ^ (1<<19); }

bool disjoint(pii e1, pii e2) {
	if (e1.fst == e2.fst) return false;
	if (e1.fst == e2.snd) return false;
	if (e1.snd == e2.fst) return false;
	if (e1.snd == e2.snd) return false;
	return true;
}

// responde si hay dos elementos que no coinciden en ninguna componente
bool hay_disjoint(vector<pii> ps) {
	sort(all(ps));
	ps.erase(unique(all(ps)), end(ps));

	if (sz(ps) < 2) return false;

	forn(i,sz(ps)) {
		forn(_,20) {
			int j = rand() % sz(ps);
			if (disjoint(ps[i], ps[j]))
				return true;
		}
	}

	return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	uf_init();

	int n,m;
	cin >> n >> m;

	map<int, vector<pii>> bb;

	forn(_, m) {
		int u,v,b;
		cin >> u >> v >> b;
		--u; --v;
		bb[-b].pb({u,v});
	}

	set<int> ans;

	bool puedo_dividir = true;
	for (auto& [b, es] : bb) {

		// entre las aristas de belleza b,
		// intento pintar una de rojo y la otra de azul
		// si puedo, entonces se puede hacer con belleza b
		// despues intento matar esas aristas para pasar a una belleza menor

		vector<pii> joinable_edges;
		for (auto [u,v] : es) {
			// me quedo con las aristas que pueden pintarse de un solo color
			if (not uf_conn(u, neg(v))) {
				joinable_edges.pb({u,v});
			}
		}

		// busco un par de aristas que pueden ser de colores distintos
		// si las hay, entonces ponemos una de cada color y las dos componentes tienen belleza b
		vector<pii> intervals;
		for (auto [u,v] : joinable_edges)
			intervals.pb({ uf_find(u), uf_find(v) });
		bool dis = hay_disjoint(move(intervals));
		if (dis) ans.insert(-b);

		// mato las aristas de belleza b marcando que los vertices que conectan son de distinto color
		for (auto [u, v] : es) {
			uf_join(u, neg(v));
			uf_join(v, neg(u));
		}

		// si alguna arista de belleza b si o si es de un solo color
		// entonces no es posible pasar a una belleza menor asique cortamos
		for (auto [u,v] : es) {
			if (uf_conn(u, v)) {
				puedo_dividir = false;
			}
		}

		if (!puedo_dividir) {
			break;
		}
	}

	// si pude cortar todas las aristas, entonces puedo 2-colorear
	// en este caso, no habria aristas y la belleza seria cero
	if (puedo_dividir) {
		ans.insert(0);
	}

	if (ans.empty()) {
		cout << "IMPOSSIBLE\n";
	} else {
		for (int x : ans) cout << x << '\n';
	}
    
    return 0;
}
