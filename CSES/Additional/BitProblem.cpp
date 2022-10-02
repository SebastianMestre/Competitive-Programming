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

const ll MAXN = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int a[MAXN];

int cant1[1<<20];
int cant2[1<<20];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;

	forn(i,n) cin >> a[i];
	forn(i,n) cant1[a[i]] += 1, cant2[a[i]] += 1;

	forn(b, 20){
		forn(x, 1<<20){
			int y = x ^ (1<<b);
			if (y < x) cant1[x] += cant1[y];
			if (x < y) cant2[x] += cant2[y];
		}
	}

	const int U = (1<<20)-1;

	forn(i,n){
		int x = a[i];
		int notx = x^U;
		cout << cant1[x] << " " << cant2[x] << " " << n-cant1[notx] << "\n";
	}

    return 0;
}
