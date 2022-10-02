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
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int n, m;
int fullmask;

int memo[1005][15][1030];

int dp(int i, int j, int v) {
	if (i == m) return v == 0;
	if (memo[i][j][v] != -1) return memo[i][j][v];
	ll ans = dp(i+1, 0, v ^ fullmask);
	forr(k, j, n-2 + 1) {
		if (((3<<k)&v) == 0) {
			ans += dp(i, k+2, v | (3<<k));
			ans %= MOD;
		}
	}
	return memo[i][j][v] = ans;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	memset(memo, -1, sizeof(memo));

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> m;
	fullmask = (1<<n)-1;
	cout << dp(0, 0, 0) << '\n';
    
    return 0;
}
