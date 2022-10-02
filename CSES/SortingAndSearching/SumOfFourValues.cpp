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

const ll MAXN = 1e3+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int n;
int x;
int a[MAXN];

const int FUNNY_CONSTANT = 0xdeadbee5;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> x;
	forn(i,n) cin >> a[i];

	unordered_map<int, pii> left_sums;
	forn(i,n-1) {
		forr(j,i+1,n){
			int s = a[i] + a[j];
			int r = x - s;

			auto it = left_sums.find(r ^ FUNNY_CONSTANT);
			if (it == left_sums.end()) continue;

			auto v = it->snd;
			int i1 = v.fst+1, i2 = v.snd+1, i3 = i+1, i4 = j+1;

			cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << '\n';
			return 0;
		}

		forn(j,i){
			int s = a[i] + a[j];
			left_sums[s ^ FUNNY_CONSTANT] = {j, i};
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}
