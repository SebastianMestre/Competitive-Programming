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

int n;

struct project {
	int a, b;
	int p;
};

bool operator< (project x, project y) {
	return make_pair(x.a, x.b) < make_pair(y.a, y.b);
}

project ps[MAXN];

int find_starts_at_least(int time) {
	return lower_bound(ps, ps+n, project{time, 0, 0}) - ps;
}

ll memo[MAXN];
ll f(int i) {
	if (i == n) return 0;
	if (memo[i]) return memo[i];
	ll self = ps[i].p + f(find_starts_at_least(ps[i].b+1));
	return memo[i] = max(self, f(i+1));
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n;
	forn(i,n) cin >> ps[i].a >> ps[i].b >> ps[i].p;

	sort(ps,ps+n);

	cout << f(0) << '\n';

    return 0;
}
