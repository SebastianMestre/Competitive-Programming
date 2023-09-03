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

// par {pendiente, corrimiento}
using Recta = pll;

vector<Recta> cht_init(vector<Recta> v) {
	sort(all(v));
	vector<Recta> u(sz(v));
	int j = 0;
	for (auto z : v) {
		if (j >= 1 && u[j-1].fst == z.fst) {
			j--;
		} else while (j >= 2) {
			Recta x = u[j-2], y = u[j-1];
			if ((y.snd-x.snd) * (y.fst-z.fst) >=
			    (z.snd-y.snd) * (x.fst-y.fst))
				j--;
			else break;
		}
		u[j++] = z;
	}
	u.resize(j);
	return u;
}

ll cht_query(vector<Recta> const& v, ll x) {
	int n = sz(v)-1;
	int lo = -1;
	int hi = n;
	while (hi - lo > 1) {
		int mi = (hi + lo) / 2;
		if ((v[mi+1].snd-v[mi].snd)>x*(v[mi].fst-v[mi+1].fst)) {
			lo = mi;
		} else {
			hi = mi;
		}
	}
	// punto lo a la izquierda (rectas lo y   lo+1)
	// punto hi a la derecha   (rectas lo+1 y lo+2)
	return x*v[lo+1].fst+v[lo+1].snd;
}

ll a[MAXN];

ll dnc(int l, int r) {
	if (r-l == 1) return a[l];

	int c = (l+r)/2;

	ll la = dnc(l, c);
	ll ra = dnc(c, r);

	vector<pll> rectas(r-c);

	{ ll w = 0, s = 0;
	forr(k, 1, r-c+1) {
		s += a[c+k-1];
		w += ll(k) * a[c+k-1];
		// recta "y = s*x+w"
		rectas[k-1] = {s, w};
	} }

	rectas = cht_init(std::move(rectas));

	ll ca = 0;
	ll w = 0, s = 0;
	forr(k, 1, c-l+1) {
		s += a[c-k];
		w += s;
		ll myans = w + cht_query(rectas, k);
		ca = max(ca, myans);
	}

	return max({la, ca, ra});
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	forn(i, n) cin >> a[i];

	ll ans = 0;

	if (n < 2) {
		forn(i, n) ans = max(ans, a[i]);
		cout << ans << "\n";
		return 0;
	}

	auto da = dnc(0, n);
	// db(da);
	ans = max(ans, da);

	cout << ans << "\n";

	return 0;
}
