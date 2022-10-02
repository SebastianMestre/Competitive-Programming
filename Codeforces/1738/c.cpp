#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=int(a);--i)
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

const ll MAXN = 1e2+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int n;
int a[MAXN];
char dpA[105][105][2];
char dpB[105][105][2];

char A(int e, int o, bool p);
char B(int e, int o, bool p);

char A(int e, int o, bool p) {
	if (e == 0 && o == 0) return p == 0;
	char& res = dpA[e][o][p];
	if (res != -1) return res;

	if (e == 0) return res = B(e, o-1, !p);
	if (o == 0) return res = B(e-1, o, p);
	return res = B(e-1, o, p) | B(e, o-1, !p);
}

char B(int e, int o, bool p) {
	if (e == 0 && o == 0) return p == 0;
	char& res = dpB[e][o][p];
	if (res != -1) return res;

	if (e == 0) return res = A(e, o-1, p);
	if (o == 0) return res = A(e-1, o, p);
	return res = A(e-1, o, p) & A(e, o-1, p);
}

void solve() {
	cin >> n;
	forn(i,n) cin >> a[i];

	int cant_evn = 0;
	int cant_odd = 0;
	forn(i,n) (a[i]%2==0?cant_evn:cant_odd)++;

	memset(dpA, -1, sizeof(dpA));
	memset(dpB, -1, sizeof(dpB));

	cout << (A(cant_evn, cant_odd, 0)?"Alice":"Bob") << '\n';
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t; cin >> t;
	forn(_,t) solve();
    
    return 0;
}
