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

const ll MAXN = 1e6+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

ll D(int n);
ll S(int n);

int memod[MAXN];
int memos[MAXN];

ll D(int n) {
	if (n == 1) return 1;
	if (memod[n]) return memod[n];
	return memod[n] = (2*D(n-1) + S(n-1)) % MOD;
}

ll S(int n) {
	if (n == 1) return 1;
	if (memos[n]) return memos[n];
	return memos[n] = (D(n-1) + 4*S(n-1)) % MOD;
}

int f(int n) {
	return (D(n) + S(n)) % MOD;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t;
	cin >> t;

	forn(asdasd,t) {
		int n;
		cin >> n;
		cout << f(n) << '\n';
	}
    
    return 0;
}
