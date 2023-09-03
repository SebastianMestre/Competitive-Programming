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
const ll MOD = 1000000007;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

const ll SIZE = 100;

#define RAYA cerr << "==================\n";


template<int W>
struct mat {
	ll (*data)[W] = {};
	mat(){ data = (ll(*)[W])calloc(W*W, sizeof(ll)); }
	static mat one() {
		mat result = {};
		forn(i,W) result.data[i][i] = 1;
		return result;
	}
};

template<int W>
struct vec {
	ll (*data) = {};
	vec() { data = (ll(*))calloc(W, sizeof(ll)); }
};




template<int W>
mat<W> operator* (mat<W> m1, mat<W> m2) {
	mat<W> result = {};
	forn(i,W) forn(j,W) forn(k,W) {
		result.data[i][j] += (m1.data[i][k] * m2.data[k][j]) % MOD;
		result.data[i][j] %= MOD;
		result.data[i][j] += MOD;
		result.data[i][j] %= MOD;
	}
	return result;
}

template<int W>
vec<W> operator* (mat<W> m1, vec<W> m2) {
	vec<W> result = {};
	forn(i,W) forn(k,W) {
		result.data[i] += (m1.data[i][k] * m2.data[k]) % MOD;
		result.data[i] %= MOD;
		result.data[i] += MOD;
		result.data[i] %= MOD;
	}
	return result;
}

template<typename M>
M potlog(M x, ll n) {
	M acc = M::one();
	while (n) {
		if (n&1) acc = acc * x;
		x = x * x;
		n /= 2;
	}
	return acc;
}


template<int W>
void print(mat<W> m) {
	forn(i,W){
		forn(j,W){
			cerr << m.data[i][j] << ' ';
		}
		cerr << '\n';
	}
}
 
template<int W>
void print(vec<W> m) {
	forn(i,W){
		cerr << m.data[i] << ' ';
		cerr << '\n';
	}
}



mat<SIZE> rec(vector<int> const& c, int m) {
	mat<SIZE> result;

	forn(i, c.size()) result.data[c[i]%m][0] += 1;
	forr(i, 1, m) forn(j,m)
		result.data[(j+i)%m][i] = result.data[j][0];

	return result;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n,l,m;
	cin >> n >> l >> m;
	vector<int> cfirst(n);
	vector<int> c(n);
	vector<int> clast(n);

	forn(i,n) cin >> cfirst[i];
	forn(i,n) cin >> c[i];
	forn(i,n) cin >> clast[i];
	forn(i,n) clast[i] += c[i];
    
	vec<SIZE> init;
	init.data[0] = 1;

// 	RAYA;
// 	print(rec(cfirst, m));
// 	RAYA;
// 	print(rec(cfirst, m) * init);
// 	RAYA;
// 	print(rec(c, m) * (rec(cfirst, m) * init));
// 	RAYA;
// 	print(rec(c,m) * rec(c, m) * (rec(cfirst, m) * init));
// 	RAYA;
// 	print(rec(clast, m) * (rec(c, m) * (rec(cfirst, m) * init)));
// 	RAYA;

	auto ans = rec(clast, m) * (potlog(rec(c, m), l-2) * (rec(cfirst, m) * init));

	cout << ans.data[0] << '\n';

    return 0;
}
