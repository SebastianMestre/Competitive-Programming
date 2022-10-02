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

const ll MAXN = 3e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int a[MAXN];
ll ft[MAXN];
ll q_(int i) {
	ll ans = 0;
	for(i+=1; i > 0; i-=i&-i)
		ans += ft[i];
	return ans;
}

void u_(int i, int x) {
	for(i+=1; i < MAXN; i+=i&-i)
		ft[i] += x;
}

void update(int i, int x) { u_(i,x); }
ll query(int l, int r) { return q_(r-1) - q_(l-1); }

struct Q { int l, r, k; };

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n; cin >> n;
	forn(i,n) cin >> a[i];

	vector<int> pa(n); forn(i,n) pa[i] = i;
	sort(all(pa), [&](int i, int j) { return a[i] < a[j]; });

	int q; cin >> q;
	vector<Q> qs(q);
	forn(i, q) cin >> qs[i].l >> qs[i].r >> qs[i].k;
	forn(i, q) qs[i].l -= 1;

	vector<int> pq(q); forn(i, q) pq[i] = i;
	sort(all(pq), [&](int i, int j) { return qs[i].k < qs[j].k; });

	vector<int> ans(q);

	int jj = 0; int j = pa[jj];
	for (int i : pq) {
		int l = qs[i].l;
		int r = qs[i].r;
		int k = qs[i].k;

		while (jj < n && a[pa[jj]] <= k) {
			update(pa[jj], 1);
			jj++;
		}

		// cerr << "QUERY [" << l << ".." << r << ") (leq " << k << ") ===> " << query(l,r) << '\n';
		ans[i] = (r-l) - query(l, r);
	}

	for (int x : ans) cout << x << '\n';

    return 0;
}
