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

	ll n;
	cin >> n;

	ll suma = n*(n+1)/2;
	if (suma % 2 == 1) {
		cout << "NO\n";
		return 0;
	}

	int pricorte = -1;

	ll target = suma / 2;
	for (int i = n; i >= 1; i--) {
		if (i <= target) {
			target -= i;
		} else {
			pricorte = i;
			break;
		}
	}

	cout << "YES\n";

	int cant = (n-pricorte)+(target != 0);
	cout << cant << '\n';
	for (int i = n; i > pricorte; i--) cout << i << ' ';
	if (target != 0) cout << target << ' ';
	cout << '\n';
    
	cout << n-cant << '\n';
	for (int i = pricorte; i > target; i--) cout << i << ' ';
	for (int i = target-1; i >= 1; i--) cout << i << ' ';
	cout << '\n';

    return 0;
}
