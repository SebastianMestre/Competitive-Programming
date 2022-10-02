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

	int x, n;
	cin >> x >> n;

	set<int> lights;

	lights.insert(0);
	lights.insert(x);

	map<int, int> histo;

	histo[x] += 1;

	forn(i,n){
		int p;
		cin >> p;

		auto ir = lights.insert(p);
		auto it = ir.first;
		int left = *prev(it);
		int right = *next(it);

		int w = right-left;

		auto wit = histo.find(w);
		wit->second -= 1;
		if (wit->second <= 0) histo.erase(wit);

		int l = p-left;  histo[l] += 1;
		int r = right-p; histo[r] += 1;

		cout << histo.rbegin()->first << ' ';
	}
	cout << '\n';

    
    return 0;
}
