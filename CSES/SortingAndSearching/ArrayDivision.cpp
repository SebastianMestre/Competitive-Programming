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

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> xs(n);
	forn(i,n) cin >> xs[i];

	ll sum = 0;
	forn(i,n) sum += xs[i];

	ll lo = 0, hi = n * 1000000000ll;

	while (hi - lo > 1) {
		ll mi = (hi+lo)/2;

		bool puedo = true;
		ll sum_so_far = 0;
		int cortes = 0;
		forn(i, n) {
			if (xs[i] > mi) puedo = false;
			if (sum_so_far + xs[i] > mi) {
				sum_so_far = 0;
				cortes++;
			}
			sum_so_far += xs[i];
		}
		
		int bloques = cortes + 1;
		if (bloques > k) puedo = false;

		if (puedo) {
			hi = mi;
		} else {
			lo = mi;
		}
	}

	cout << hi << "\n";

}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
