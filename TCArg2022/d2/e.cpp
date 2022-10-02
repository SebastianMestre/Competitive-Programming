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

const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

// MAXN must be power of 2 !!
const int MAXN = 1<<20; //FFT

//¡¡OJO!! Chequear si los coeficientes son int o ll
typedef vector<int> poly;


//FFT
struct CD
{
    double r, i;
    CD(double r = 0, double i = 0):r(r), i(i){}
    double real() const{return r;}
    void operator/=(const int c){r/=c, i/=c;}
};

CD operator*(const CD& a, const CD& b) {return CD(a.r*b.r - a.i*b.i, a.r*b.i + a.i*b.r);}
CD operator+(const CD& a, const CD& b) {return CD(a.r + b.r, a.i + b.i);}
CD operator-(const CD& a, const CD& b) {return CD(a.r - b.r, a.i - b.i);}
const double pi = acos(-1.0);


CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];

void dft(CD* a, int n, bool inv){
	forr(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
//		CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)forr(i,0,n)a[i]/=n; // FFT
}


poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	forr(i,0,m){R[i]=0;forr(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	forr(i,0,m)cp1[i]=0,cp2[i]=0;
	forr(i,0,p1.size())cp1[i]=p1[i];
	forr(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	forr(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	forr(i,0,n)res.pb((ll)floor(cp1[i].real()+0.5)); // FFT
//	forr(i,0,n)res.pb(cp1[i].x); // NTT
	return res;
}

poly conv(poly& p1, poly& p2) {
	poly res = multiply(p1, p2);
	forn (i, res.size()) {
		if (res[i] > 0) res[i] = 1;
		else            res[i] = 0;
	}
	while (res.size() > 1 && res.back() == 0) {
		res.pop_back();
	}
	return res;
}

poly potlog(poly p, int n) {
	poly acc = {1};
	while (n) {
		if (n % 2 == 1) acc = conv(acc, p);
		p = conv(p, p);
		n /= 2;
	}
	return acc;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> p(1001, 0);
	forn(i,n){
		int a_i; cin >> a_i;
		p[a_i] = 1;
	}

	while (p.size() > 1 && p.back() == 0) p.pop_back();

	poly res = potlog(p, k);

	char const* sep = "";
	forn (i, res.size()) {
		if (res[i]) {
			cout << sep << i;
			sep = " ";
		}
	}
	cout << '\n';

    return 0;
}

