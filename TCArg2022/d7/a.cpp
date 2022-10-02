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


double caso1(double a, double b) {
	return  0.5 + a/(16*b);
}

double caso2(double a, double b) {
	return 1 - b/a;
}

double ans(double a, double b) {
	if (b == 0)   return 1;
	if (a == 0)   return 0.5;
	if (a <= 4*b) return caso1(a, b);
	else          return caso2(a, b);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int T;
	cin >> T;
	forn(t,T) {
		double a,b;
		cin >> a >> b;
		printf("%.9lf\n", ans(a,b));
	}
    
    return 0;
}
