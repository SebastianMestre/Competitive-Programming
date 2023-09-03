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
#define RAYA cerr << "==================\n";

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

const ll MOD1 = 1000000007;
const ll MOD2 = MOD1 - 1;

template<int W>
struct mat {
	ll data[W][W] = {};
	static mat one() {
		mat result = {};
		forn(i,W) result.data[i][i] = 1;
		return result;
	}
};

template<int W>
struct vec {
	ll data[W] = {};
};

struct sca {
	ll data = {};

	static sca one() {
		return {1};
	}
};

template<int W>
mat<W> operator* (mat<W> m1, mat<W> m2) {
	mat<W> result = {};
	forn(i,W) forn(j,W) forn(k,W) {
		result.data[i][j] += (m1.data[i][k] * m2.data[k][j]) % MOD2;
		result.data[i][j] %= MOD2;
		result.data[i][j] += MOD2;
		result.data[i][j] %= MOD2;
	}
	return result;
}

template<int W>
vec<W> operator* (mat<W> m1, vec<W> m2) {
	vec<W> result = {};
	forn(i,W) forn(k,W) {
		result.data[i] += (m1.data[i][k] * m2.data[k]) % MOD2;
		result.data[i] %= MOD2;
		result.data[i] += MOD2;
		result.data[i] %= MOD2;
	}
	return result;
}

sca operator* (sca m1, sca m2) {
	return {(m1.data * m2.data) % MOD1};
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

sca find_fx_raised(sca f1, vec<3> vf1, mat<3> mf_raised) {
	return potlog(f1, (mf_raised*vf1).data[0]);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	ll n;
	ll f1,f2,f3,c;
	cin >> n >> f1 >> f2 >> f3 >> c;

	if (n == 1) { cout << f1 << '\n'; return 0; }
	if (n == 2) { cout << f2 << '\n'; return 0; }
	if (n == 3) { cout << f3 << '\n'; return 0; }

	mat<3> mf = {{
		{1, 1, 1},
		{1, 0, 0},
		{0, 1, 0},
	}};

	mat<3> mf_raised = potlog(mf, n-3);

	sca f1_raised = find_fx_raised({f1}, {{0,0,1}}, mf_raised);
	sca f2_raised = find_fx_raised({f2}, {{0,1,0}}, mf_raised);
	sca f3_raised = find_fx_raised({f3}, {{1,0,0}}, mf_raised);

	if (n == 4) {
		sca c_raised = sca{c} * sca{c};
		sca result =  c_raised * f1_raised * f2_raised * f3_raised;
		cout << result.data << '\n';
		return 0;
	}

	mat<5> mc = {{
		{3, -2,  0, -1,  1},
		{1,  0,  0,  0,  0},
		{0,  1,  0,  0,  0},
		{0,  0,  1,  0,  0},
		{0,  0,  0,  1,  0},
	}};
	vec<5> c_init = {{ 6, 2, 0, 0, 0 }};
	ll c_expo = (potlog(mc, n-5) * c_init).data[0];
	sca c_raised = potlog(sca{c}, c_expo);

	sca result =  c_raised * f1_raised * f2_raised * f3_raised;

	cout << result.data << '\n';


    return 0;
}

