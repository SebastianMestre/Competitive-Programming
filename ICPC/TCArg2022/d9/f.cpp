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

using Sc = ll; // scalar, asi se puede cambiar por double u otra cosa si hace falta
struct pt { Sc x, y; };

pt operator+ (pt const& a, pt const& b) { return {a.x + b.x, a.y + b.y}; } // suma
pt operator- (pt const& a, pt const& b) { return {a.x - b.x, a.y - b.y}; } // diferencia
pt operator* (Sc const& x, pt const& p) { return {x * p.x, x * p.y}; } // producto por un escalar
bool operator<(pt const& a, pt const& b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }
bool operator==(pt const& a, pt const& b) { return a.x == b.x && a.y == b.y; }

Sc det(pt const& a, pt const& b) { return a.x*b.y - a.y*b.x; } // determinante
Sc dot(pt const& a, pt const& b) { return a.x*b.x + a.y*b.y; } // producto escalar
Sc len_sq(pt const& p) { return dot(p, p); } // modulo cuadrado
double len(pt const& p) { return hypot(p.x, p.y); } // modulo

bool ccw(pt const& o, pt const& a, pt const& b) { return det(a - o, b - o) > 0; } // responde si, centrado en o, ir de a hacia b es un giro contra-reloj
bool cw(pt const& o, pt const& a, pt const& b) { return det(a - o, b - o) < 0; } // responde si, centrado en o, ir de a hacia b es un giro como el reloj


pt ps[MAXN];

ll miabs(ll x) {
	if (x < 0) return -x;
	return x;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


	int n;
	cin >> n;
	forn(i,n) cin >> ps[i].x >> ps[i].y;

	vector<int> perm(n);
	forn(i,n)perm[i]=i;
	sort(all(perm), [](int i, int j) {
		return make_pair(ps[i].x, ps[i].y) < make_pair(ps[j].x, ps[j].y);
	});

	int i = perm[0];
	int j = perm[1];
	{
		ll dis2 = len_sq(ps[i] - ps[j]);
		for(auto idx : perm) {
			if (idx == i) continue;
			if (idx == j) continue;
			ll dis2_yo = len_sq(ps[i] - ps[idx]);
			if (dis2_yo < dis2) {
				dis2 = dis2_yo;
				j = idx;
			}
		}
	}
	int k = -1;
	{
		ll dis2 = 0;
		for(auto idx : perm) {
			if (idx == i) continue;
			if (idx == j) continue;
			if (idx == k) continue;
			if (det(ps[i]-ps[j], ps[i]-ps[idx]) == 0) continue;

			// cerr << "HOLA COMO VA?\n";

			ll dis2_yo = len_sq(ps[i] - ps[idx]);
			if (k == -1 || dis2_yo < dis2) {
				dis2 = dis2_yo;
				k = idx;
			}
		}
	}

	// db(det(ps[j] - ps[i], ps[k] - ps[i]));

	printf("%d %d %d\n", i+1, j+1, k+1);

	return 0;
}
