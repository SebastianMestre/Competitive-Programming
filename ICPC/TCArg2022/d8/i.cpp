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

const ll MAXN = 5e3+100;
const int INF = 1e8;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int c[MAXN];
int d[MAXN];
int e[MAXN];

int dp[MAXN][MAXN];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n; cin >> n;
	forn(i,n) cin >> c[i];

	int m = 0;
	forn(i,n) if (i == 0 || c[i-1] != c[i])
		d[m++] = c[i];

	copy(d,d+m,e);
	reverse(e,e+m);

	forn(i,m) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	forr(i,1,m+1) {
		forr(j,1,m+1) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if (d[i-1] == e[j-1])
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
		}
	}

	int ans = INT_MAX;
	forn(i, m) {
		int left = i;
		int right = m-i-1;
		int common = dp[i][m-(i+1)];
		int current = left + right - common;
		ans = min(ans, current);
	}

	cout << ans << '\n';

	return 0;
}
