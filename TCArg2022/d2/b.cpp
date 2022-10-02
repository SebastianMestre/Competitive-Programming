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

const int MAXN = 1002;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int n, k;
vector<vector<int>> perm;
vector<vector<int>> inv;

bool todosok(int old, int val) {
	forr (j, 1, k)
		if (!(inv[j][old] < inv[j][val]))
			return false;
	return true;
}

int memo[MAXN][MAXN];
int dp(int a, int b) {
	if (b > n) return 0;
	if (memo[a][b] != -1) return memo[a][b];
	int old = perm[0][a];
	int val = perm[0][b];
	int res = dp(a, b+1);
	if (todosok(old, val)) {
		int op2 = 1 + dp(b, b+1);
		res = max(res, op2);
	}
	return memo[a][b] = res;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	memset(memo, -1, sizeof(memo));

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> k;

	perm.resize(k);
	forn(j,k) perm[j].push_back(0);
	forn(j,k) forn(i,n) {
		int x; cin >> x;
		perm[j].push_back(x);
	}

	inv.resize(k);
	forn(j,k) inv[j].resize(n+1);
	forn(j,k) forn(i, n+1) inv[j][perm[j][i]] = i;

	cout << dp(0,1) << '\n';
    
    return 0;
}

