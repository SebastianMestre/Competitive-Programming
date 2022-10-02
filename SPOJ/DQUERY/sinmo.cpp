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

const ll MAXN = 3e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

int a[MAXN];

pii flip(pii p) { return {p.snd, p.fst}; }

const int B = 1000;
ll S[MAXN/B+1][B+1];
int A[MAXN/B+1][B+1];

// O(B)
void update(int p, int x) {
	// cerr << "UPDATE " << p << " " << x << "\n";
	int bloque = p/B;
	A[bloque][p%B] = x;
	S[bloque][0] = 0;
	forn(i,B) {
		S[bloque][i+1] = S[bloque][i] + A[bloque][i];
	}
}

// O(N/B)
ll query(int l, int r) {
	// cerr << "QUERY " << l << " " << r << "\n";
	int Lb = l/B;
	int Ll = l%B;
	int Lr = B;

	int Rb = r/B;
	int Rl = 0;
	int Rr = r%B;

	if (Rb == Lb)
		return S[Rb][Rr] - S[Lb][Ll];

	ll  Ls = S[Lb][Lr] - S[Lb][Ll];
	ll  Rs = S[Rb][Rr] - S[Rb][Rl];

	ll  Bs = 0;
	forr(b, Lb+1, Rb)
		Bs += S[b][B];

	return Ls + Bs + Rs;
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;

	forn(i,n) cin >> a[i];

	int q;
	cin >> q;
	vector<pii> queries(q);
	forn(i,q) cin >> queries[i].fst >> queries[i].snd;
	forn(i,q) queries[i].fst -= 1;

	vector<int> perm(q); forn(i,q) perm[i] = i;
	sort(all(perm), [&](int a, int b){
		return flip(queries[a]) < flip(queries[b]);
	});

	vector<int> latest(1000001, -1);
	vector<int> ans(q);

	int i = 0;
	for (int qi : perm) {
		for (; i < queries[qi].snd; i++) {
			if (latest[a[i]] != -1)
			update(latest[a[i]], 0);
			latest[a[i]] = i;
			update(latest[a[i]], 1);
		}
		ans[qi] = query(queries[qi].fst, queries[qi].snd);
	}

	auto sep = "";
	for (int x : ans) cout << exchange(sep, " ") << x;
	cout << '\n';

    return 0;
}
