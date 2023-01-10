#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
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

const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

const int MAXN = 200000, K=512;
const int BUCKETS = (MAXN+K-1)/K;

int a[MAXN];
int b[BUCKETS];
int n;

void init() {
	forn(i, BUCKETS) b[i] = INT_MAX;
	forn(i, n) b[i/K] = min(b[i/K], a[i]);
}

int query(int l, int r) {
	int lb=l/K, rb=r/K;
	if (lb == rb){
		int res = INT_MAX;
		forr(i,l,r) res = min(res, a[i]);
		return res;
	}
	int res = INT_MAX;
	forr(i,l,(lb+1)*K) res=min(res, a[i]);
	forr(i,lb+1,rb)    res=min(res, b[i]);
	forr(i,rb*K,r)     res=min(res, a[i]);
	return res;
}



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int q;
	cin >> n >> q;
	forn(i,n) cin >> a[i];
	init();
	forn(_,q){
		int l,r; cin >> l >> r; --l; --r;
		cout << query(l, r+1) << '\n';
	}

    return 0;
}
