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

const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);
const int MAXN = 2e5+100;

int n, q;
int a[MAXN];
pii qs[MAXN];
int ans[MAXN];

#define USE_FLATMAP 1

int amount = 0;

#if USE_FLATMAP
const int BITS = 22;
const int HTSIZE = 1<<BITS;
int cant[HTSIZE];
int key[HTSIZE];
size_t fibonacci_hash(size_t hash) {
	const int shift_amount = 64 - BITS;
    hash ^= hash >> shift_amount;
    return (11400714819323198485llu * hash) >> shift_amount;
}
#else
unordered_map<int,int> mapa;
#endif

void inc(int x) {
#if USE_FLATMAP
	// cerr << "ENTER " << __func__ << "(" << x << ")" << '\n';
	auto h = fibonacci_hash(x);

	int hole = -1;
	for (; cant[h] != 0; h++, h%=HTSIZE) {
		if (hole == -1 && cant[h] < 0) hole = h;
		if (key[h] == x) break;
	}

	if (key[h] != x && hole != -1) h = hole;

	if (cant[h] == -1) cant[h] = 0;

	if (cant[h]++ == 0) {
		amount++;
		key[h] = x;
	}
	// cerr << "EXIT " << __func__ << '\n';
#else
	mapa[x]++;
	amount = sz(mapa);
#endif
}

void dec(int x) {
#if USE_FLATMAP
	// cerr << "ENTER " << __func__ << "(" << x << ")" << '\n';
	auto h = fibonacci_hash(x);

	while (key[h] != x) h++, h%=HTSIZE;

	if (--cant[h] == 0) {
		cant[h] = -1;
		key[h] = -1;
		amount--;
	}
	// cerr << "EXIT " << __func__ << '\n';
#else
	auto it = mapa.find(x);
	it->snd -= 1;
	if (it->snd == 0) mapa.erase(it);
	amount = sz(mapa);
#endif
}

int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#if USE_FLATMAP
	memset(key, -1, sizeof(key));
#endif

	cin >> n >> q;
	forn(i,n) cin >> a[i];

	forn(i,q){
		auto&l=qs[i].fst;
		auto&r=qs[i].snd;
		cin >> l >> r;
		l--;
	}

	vector<int> p(q);
	forn(i,q) p[i] = i;
	sort(all(p), [](int i, int j) {
		const int B = 450;
		int bi=qs[i].fst/B, bj=qs[j].fst/B;
		if (bi != bj) return bi < bj;
		else if (bi%2) return qs[i].snd > qs[j].snd;
		else return qs[i].snd < qs[j].snd;
	});

	int l = 0;
	int r = 0;
	for (int i : p) {
		while (r < qs[i].snd) inc(a[r++]);
		while (qs[i].fst < l) inc(a[--l]);
		while (qs[i].snd < r) dec(a[--r]);
		while (l < qs[i].fst) dec(a[l++]);

		ans[i] = amount;
	}


	forn(i,q) {
		cout << ans[i] << '\n';
	}


    return 0;
}
