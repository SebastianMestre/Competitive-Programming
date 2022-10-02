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

#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll MAXN = (1<<20) + 100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

ll c1[MAXN+9],c2[MAXN+9];  // MAXN must be power of 2 !!
void fht(ll* p, int n, bool inv){
	for(int l=1;2*l<=n;l*=2)for(int i=0;i<n;i+=2*l)forr(j,0,l){
		ll u=p[i+j],v=p[i+l+j];
		//if(!inv)p[i+j]=u+v,p[i+l+j]=u-v; // XOR
		//else p[i+j]=(u+v)/2,p[i+l+j]=(u-v)/2;
		//if(!inv)p[i+j]=v,p[i+l+j]=u+v; // AND
		//else p[i+j]=-u+v,p[i+l+j]=u;
		if(!inv)p[i+j]=u+v,p[i+l+j]=u; // OR
		else p[i+j]=v,p[i+l+j]=u-v;
	}
}

// like polynomial multiplication, but XORing exponents
// instead of adding them (also ANDing, ORing)
vector<ll> multiply(vector<ll>& p1, vector<ll>& p2){
	int n=1<<(32-__builtin_clz(max(sz(p1),sz(p2))-1));
	forr(i,0,n)c1[i]=0,c2[i]=0;
	forr(i,0,sz(p1))c1[i]=p1[i];
	forr(i,0,sz(p2))c2[i]=p2[i];
	fht(c1,n,false);fht(c2,n,false);
	forr(i,0,n)c1[i]*=c2[i];
	fht(c1,n,true);
	return vector<ll>(c1,c1+n);
}

const int maxn = 20;

int n, x;
int w[maxn];

ll peso(int m) {
	ll res = 0;
	forn(i,20) res += ((m>>i)&1) * w[i];
	return res;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x;
	forn(i,n) cin >> w[i];

	vector<ll> con1(1 << n);
	forn(m,1<<n) con1[m] = peso(m) <= x;

	int S = 1<<n;

	forr(i,0,S) c2[i]=con1[i];
	fht(c2,S,false);

	forr(i,0,S) c1[i]=con1[i];

	int ascensores = 1;
	while (not c1[(1<<n)-1]) {

		fht(c1,S,false);
		forr(i,0,S)c1[i]*=c2[i];
		fht(c1,S,true);

		forn(i,S){
			ll& x = c1[i];
			x = x>=1?1:0;
		}

		ascensores++;
	}
	cout << ascensores << '\n';

	return 0;
}
