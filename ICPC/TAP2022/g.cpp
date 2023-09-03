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

const ll MAXN = 1e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

using Point = pii;
using Segment = pair<Point, Point>;

map<Segment, int> mapa;
vector<int> g[MAXN];
ll area[MAXN];

ll mi_llabs(ll x) { return x<0 ? -x : x; }

ll twice_area_tri(Point p, Point q, Point r) {
	Point u = {p.fst - q.fst, p.snd - q.snd};
	Point v = {p.fst - r.fst, p.snd - r.snd};
	return mi_llabs(ll(u.fst) * v.snd - ll(u.snd) * v.fst);
}

int main(){

	int n;
	cin >> n;

	forn(u,n) {
		Point p1, p2, p3;
		cin >> p1.fst >> p1.snd;
		cin >> p2.fst >> p2.snd;
		cin >> p3.fst >> p3.snd;

		auto add_seg = [&](Point p, Point q) {
			Segment seg = {min(p,q), max(p,q)};
			auto ir = mapa.insert({seg, u});
			if (!ir.second) {
				int v = ir.fst->snd;
				g[v].pb(u);
			}
		};

		add_seg(p1, p2);
		add_seg(p2, p3);
		add_seg(p3, p1);

		area[u] = twice_area_tri(p1,p2,p3);
	}

	vector<ll> dp(n, 0);
	dforn(u, n) {
		ll& res = dp[u];

		{
			ll op1 = 0;
			for (int v : g[u]) op1 += dp[v];
			res = max(res, op1);
		}

		int deg = sz(g[u]) + (u!=0);
		if (deg >= 3) {
			ll op2 = area[u];
			for (int v : g[u]) for (int w : g[v]) op2 += dp[w];
			res = max(res, op2);
		}
	}

	ll res = -dp[0];
	forn(u, n) res += area[u];

	cout << (res/2) << "." << (res%2?"5":"0") << '\n';
}
