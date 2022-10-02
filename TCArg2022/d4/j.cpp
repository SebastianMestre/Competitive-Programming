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

const ll MAXN = 2e5;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n);
	forn(i, n) cin >> a[i];
	forn(i, n) a[i]--;
    
	vector<int> percolor(m, n);
	vector<int> next(n,n);

	for (int i = n; i--;) {
		int c = a[i];
		next[i] = percolor[c];
		percolor[c] = i;
	}

	int res = 0;
	forn(c, m) {
		int i = percolor[c];
		int j = i;
		int cant = 1;
		for (; i != n; i = next[i], cant = cant - 1) {
			while (next[j] != n && (next[j]+1-i) - (cant+1) <= k) {
				j = next[j], cant = cant+1;
			}
			res = max(cant, res);
		}
	}

	cout << res << '\n';

    return 0;
}

