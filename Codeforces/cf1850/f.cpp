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
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

template<typename T>
ostream& operator<<(ostream& o, vector<T> const& v) {
	o << "[ ";
	for (auto const& x : v)
		o << x << " ";
	return o << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream& o, pair<T, U> const& p) {
	return o
	<< "("
	<< p.fst
	<< ","
	<< " "
	<< p.snd
	<< ")"
	;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n); forn(i, n) cin >> a[i];

	map<int, int> frec;
	forn(i, n) frec[a[i]] += 1;

	vector<int> cnt(n+1, 0);
	for (auto [k, v] : frec) {
		int pos = 0;
		while (pos <= n) {
			cnt[pos] += v;
			pos += k;
		}
	}

	int bst = 0;
	forr(i, 1, n+1)
		bst = max(bst, cnt[i]);

	cout << bst << "\n";
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;
	forn(_,t) solve();
}
