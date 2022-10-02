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
const int INF = 1e9+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int a[MAXN];
int b[MAXN];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;
	forn(i,n) cin >> a[i];

	fill(b,b+n+2,INF);

	b[0] = -1;
	forn(i,n) {
		auto it = upper_bound(b, b+n+1, a[i]);
		auto j = distance(b,it)-1;
		if (b[j] < a[i] && a[i] < b[j+1])
			b[j+1] = a[i];
	}

	int k = 0;
	while (b[k] != INF) {
		k++;
	}

	cout << (k-1) << '\n';

    return 0;
}
