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

const ll MAXN = 1000+100;
const ll INF = 1e8;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int h[MAXN];
int s[MAXN];

vector<int> m1;
vector<int> m2;

int f(int x) {
	if (x == 0) return 0;
	if (x <  0) return -INF;
	return m1[x];
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int N,X;
	cin >> N>>X;
	forn(i,N) cin >> h[i];
	forn(i,N) cin >> s[i];

	m1.resize(X+1);
	m2.resize(X+1);

	forr(n,1,N+1) {
		forr(x,1,X+1)
			m2[x] = max(
				f(x       ),
				f(x-h[n-1])+s[n-1]);
		swap(m1, m2);
	}

	cout << m1[X] << '\n';
    
    return 0;
}
