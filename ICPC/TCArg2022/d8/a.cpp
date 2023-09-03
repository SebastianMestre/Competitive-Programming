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

unordered_map<ll, ll> memo;

ll m;

ll dp(ll n) {
	if (n < 0) return 0;
	if (n < m) return 1;

	{
		auto it = memo.find(n);
		if (it != memo.end())
			return it->second;
	}

	ll corte = n/2;

	ll sin_cruce = (dp(corte) * dp(n-corte)) % MOD;

	ll con_cruce = 0;
	forr(i, 1, m) {
		con_cruce += (dp(corte - i) * dp(n - (corte - i + m))) % MOD;
		con_cruce %= MOD;
	}

	return memo[n] = (sin_cruce + con_cruce) % MOD;
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n;
	cin >> n >> m;

	cout << dp(n) << '\n';
    
    return 0;
}
