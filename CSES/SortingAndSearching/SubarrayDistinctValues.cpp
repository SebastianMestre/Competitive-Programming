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

const ll MAXN = 2e5+100;
const ll LOG2N = 17;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int ft[MAXN];
void update(int i, int x) {
	for (++i; i < MAXN; i += i&-i)
		ft[i] += x;
}

int query(int i) {
	int res = 0;
	for (; i > 0; i -= i&-i)
		res += ft[i];
	return res;
}

// estilo lower_bound:
// primer i tal que query(i) >= x
int search(int x) {
	if (x <= 0) return 0;
	int i = 0;
	dforn(k, LOG2N+1) {
		int j = i | (1<<k);
		if (j < MAXN && x > ft[j]) {
			x -= ft[j];
			i = j;
		}
	}
	return i + 1;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	forn(i,n) cin >> a[i];

	vector<int> b = a;
	sort(all(b));
	forn(i,n) a[i] = distance(begin(b), lower_bound(all(b), a[i]));
	vector<int> pos(n, -1);

	ll ans = 0;
	forr(i, 1, n+1) {

		int ii = i-1;
		int x = a[ii];

		if (pos[x] != -1) {
			update(pos[x], -1);
		}
		pos[x] = ii;
		update(ii, 1);

		int target = query(i) - k;
		int p = search(target);
		ans += i - p;
	}

	cout << ans << '\n';
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
