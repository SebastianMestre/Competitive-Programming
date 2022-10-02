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

int n, x;
int w[20];

pii dp[1<<20];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> x;
	forn(i,n) cin >> w[i];

	dp[0] = {1, 0};
	forr(m, 1, 1<<n) {
		pii res = {n+2, 0};
		for (int iter = m; iter;) {
			int i = 31-__builtin_clz(iter);
			int m_ = m & ~(1<<i);
			auto [a, b] = dp[m_];
			if (b+w[i] <= x) {
				res = min(res, make_pair(a, b+w[i]));
			} else {
				res = min(res, make_pair(a+1, w[i]));
			}
			iter &= ~(1<<i);
		}
		dp[m] = res;
	}

	cout << dp[(1<<n)-1].first << '\n';

    return 0;
}
