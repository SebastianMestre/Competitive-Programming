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

void solve(int testcase) {
	int n;
	cin >> n;

	vector<ll> a(n);
	forn(i,n) cin >> a[i];

	sort(all(a));
	a.push_back(1000000000000ll);

	ll t = 0;
	forr(i,1,n+1) {
		ll full = (a[i] - a[i-1]) * i;
		if (t + full <= a[i]) {
			// cerr << "OK pre-t = " << t << " | a[i] = " << a[i] << " | pos-t = " << (t+full) << "\n";
			t += full;
		} else {

			ll lo = 0;
			ll hi = 100000000000ll;

			while (hi-lo > 1) {
				ll del = (lo+hi)/2;
				if (t + del <= a[i-1] + (del/i)) {
					lo = del;
				} else {
					hi = del;
				}
			}

			t += hi;
			break;
		}
	}

	cout << "Case #" << testcase << ": " << t << '\n';
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int T;
	cin >> T;
	forn(t, T) solve(t+1);
    
    return 0;
}
