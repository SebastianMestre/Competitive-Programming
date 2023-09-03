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

const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

const int MAXN = 5000+100;

ll inv[MAXN];
ll fact[MAXN];
ll invfact[MAXN];
ll p[MAXN];

ll mulmod(ll a, ll b) { return a*b%MOD; }
ll addmod(ll a, ll b) { ll r = a+b; return r<MOD?r:r-MOD; }
ll submod(ll a, ll b) { ll r = a - b; return r>=0?r:r+MOD; }

ll choose(ll a, ll b) {
	assert(b < MAXN);
	ll result = invfact[b];
	// TODO: meter el valor que calcula el loop en una tabla
	forn(i, b) result = mulmod(result, a-i);
	return result;
}

ll caminos_rectangulo(ll ancho, ll alto) {
	if (ancho < 0) return 0;
	if (alto  < 0) return 0;
	return choose(ancho + alto, ancho);
}

void init_inv() {
	inv[1] = 1;
	fact[0] = fact[1] = 1;
	invfact[0] = invfact[1] = 1;
	forr(i, 2, MAXN) {
		inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
		fact[i] = fact[i-1] * i % MOD;
		invfact[i] = invfact[i-1] * inv[i] % MOD;
	}
}

void solve() {
	init_inv();

	int n, r;
	cin >> n >> r;

	forn(i,n) cin >> p[i];

	// quiero cantidad de arrays no crecientes 'q' tal que p[i] <= q[i] <= r (para todo i)

	dforn(i, n-1) p[i] = max(p[i+1], p[i]);
	forn(i,n) p[i] = r - p[i];

	// ahora quiero la cantidad de arrays no decrecientes 'q' tal que 0 <= q[i] <= p[i] (para todo i)

	vector<ll> dp(n+1);

	dp[0] = 1;
	// dp[i] = caminos (0, 0) --> (i, p[i-1]) que no se salen

	forr(i, 1, n+1) {
		ll& res = dp[i];
		ll altitud_final = p[i-1];

		// todos los caminos posibles
		res = caminos_rectangulo(i, altitud_final);

		forn(j, i) { // resto los que se salen en la posicion j
			if (p[j] == p[i-1]) continue;

			ll altitud_saliendo = p[j] + 1;

			ll alto  = altitud_final - altitud_saliendo;
			ll ancho = i - j;

			ll formas_llegar = dp[j];
			ll formas_seguir = caminos_rectangulo(ancho, alto);

			res = submod(res, mulmod(formas_llegar, formas_seguir));
		}
	}

	cout << dp[n] << '\n';
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
