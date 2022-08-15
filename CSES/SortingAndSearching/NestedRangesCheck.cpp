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
const ll INF = 1e9+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int ft[2*MAXN];

int ft_query(int i) {
	int result = 0;
	for (i+=1; i > 0; i -= i&-i)
		result += ft[i];
	return result;
}

void ft_update(int i, int x) {
	for (i+=1; i < 2*MAXN; i += i&-i)
		ft[i] += x;
}

pii neg_snd(pii p) { return {p.fst, -p.snd}; }

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pii> ps(n);
	forn(i,n) cin >> ps[i].fst >> ps[i].snd;

	{
		map<int,int> coords;
		forn(i,n) coords[ps[i].fst] = 0;
		forn(i,n) coords[ps[i].snd] = 0;
		int counter = 0;
		for (auto& kv : coords) kv.snd = counter++;
		forn(i,n) ps[i].fst = coords[ps[i].fst];
		forn(i,n) ps[i].snd = coords[ps[i].snd];
	}

	vector<int> ord(n);
	forn(i,n) ord[i] = i;
	sort(all(ord), [&](int i, int j) {
		return neg_snd(ps[i]) < neg_snd(ps[j]);
	});

	vector<bool> yo_contenido(n, false);
	forn(ii,n) {
		int i = ord[ii];
		pii p = ps[i];

		int despues = ii - ft_query(p.snd-1);
		yo_contenido[i] = despues != 0;

		ft_update(p.snd, 1);
	}

	fill(begin(ft), end(ft), 0);
	vector<bool> yo_contengo(n, false);
	for(int ii = n; ii--;) {
		int i = ord[ii];
		pii p = ps[i];

		int despues = ft_query(p.snd);
		yo_contengo[i] = despues != 0;

		ft_update(p.snd, 1);
	}

	forn(i,n) cout << yo_contengo [i] << ' ';
	cout << '\n';

	forn(i,n) cout << yo_contenido[i] << ' ';
	cout << '\n';

	return 0;
}
