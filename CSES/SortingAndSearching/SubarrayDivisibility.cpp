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

const ll MAXN = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);


uint64_t mul128_u64(__uint128_t lowbits, uint64_t d) {
  __uint128_t bottom_half = (lowbits & UINT64_C(0xFFFFFFFFFFFFFFFF)) * d;
  bottom_half >>= 64;
  __uint128_t top_half = (lowbits >> 64) * d;
  __uint128_t both_halves = bottom_half + top_half;
  both_halves >>= 64;
  return (uint64_t)both_halves;
}

__uint128_t computeM(uint64_t d) {
	if (d < 0) d = -d;
	__uint128_t M = UINT64_C(0xFFFFFFFFFFFFFFFF);
	M <<= 64;
	M |= UINT64_C(0xFFFFFFFFFFFFFFFF);
	M /= d;
	M += 1;
	M += ((d & (d - 1)) == 0 ? 1 : 0);
	return M;
}

// computa (a % d) dado M precalculado
// d tiene que estar en valor absoluto
// ejemplo
// auto M = computeM(MOD);
// forn(i, n) c[i] = fastmod(a[i] + b[i], M, MOD);
int64_t fastmod(int64_t a, __uint128_t M, int64_t positive_d) {
  __uint128_t lowbits = M * a;
  int64_t highbits = (int64_t)mul128_u64(lowbits, positive_d);
  return highbits - ((positive_d - 1) & (a >> 63));
}


bool is_space(char c) { return c == ' ' || c == '\n' || c == '\t'; }
bool is_digit(char c) { return '0' <= c && c <= '9'; }

int read_int() {
	char c;
	c = getchar();
	while (is_space(c)) c = getchar();
	bool is_neg = (c == '-');
	int magnitude = is_neg?0:c-'0';
	while (is_digit(c = getchar())) {
		magnitude = magnitude * 10 + (c - '0');
	}
	return is_neg?-magnitude:magnitude;
}

void solve() {
	int n = read_int();

	vector<int> a(n);
	forn(i,n) a[i] = read_int();

	vector<int> hist(n+1, 0);
	hist[0] = 1;

	ll result = 0;
	int sum = 0;

	auto M = computeM(n);

	forr(j, 0, n) {
		sum = fastmod(fastmod(sum + a[j], M, n) + n, M, n);
		result += hist[sum];
		hist[sum]++;
	}

	cout << result << '\n';
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	solve();

	return 0;
}
