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


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	vector<pii> a(n);
	forn(i,n){ cin >> a[i].fst; a[i].snd = i; }
	sort(all(a));

	forn(k,n-2) {
		int j = n;
		forr(i, k+1, n-1) {
			if (j-1 <= i) break;
			while (a[i].fst + a[j-1].fst + a[k].fst > x) j--;
			if (j-1 <= i) break;
			if (a[i].fst + a[j-1].fst + a[k].fst == x) {
				cout << a[i].snd+1 << ' ' << a[j-1].snd+1 << ' ' << a[k].snd+1 << '\n';
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE\n";
    
    return 0;
}
