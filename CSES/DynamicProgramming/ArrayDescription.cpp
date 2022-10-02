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

const ll MAXN = 1e5+100;
const ll INF = 1e18+100;
const int MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int x[MAXN];
int n, m;
int memo[MAXN][101];

int go(int i, int y) {
	if (y < 1) return 0;
	if (y > m) return 0;
	if (x[i] != 0 && x[i] != y) return 0;
	if (i == n-1) return 1;
	return memo[i][y];
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> m;
	forn(i,n) cin >> x[i];

	for (int i=n; i-->0;) {
		forr(y,1,m+1) {
			if (x[i] != 0 && x[i] != y) memo[i][y] = 0;
			else if (i == n-1) memo[i][y] = 1;
			else for (int d = -1; d <= 1; ++d) {
				memo[i][y] += go(i+1, y+d);
				memo[i][y] %= MOD;
			}
		}
	}

	int ans = 0;
	forr(y,1,m+1) {
		ans += go(0,y);
		ans %= MOD;
	}
	cout << ans << '\n';

    return 0;
}
