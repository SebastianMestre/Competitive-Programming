#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define fore(e,c) for(const auto &e : (c))
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define nn cout<<'\n'
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAXN = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

template<typename T>
ostream& operator<<(ostream& o, vector<T> const& v) {
	o << "[ ";
	for (auto const& x : v)
		o << x << " ";
	return o << "]";
}

template<typename T>
ostream& operator<<(ostream& o, set<T> const& v) {
	o << "[ ";
	for (auto const& x : v)
		o << x << " ";
	return o << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream& o, pair<T, U> const& p) {
	return o
	<< "("
	<< p.fst
	<< ","
	<< " "
	<< p.snd
	<< ")"
	;
}

void solve() {
	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	int suma = 0;

	set<int> plus;
	set<int> minus;
	forn(i,n) {
		if (s[i]=='(') { suma+=1; plus.insert(i); }
		else           { suma-=1; minus.insert(i); }
	}

	set<int> dplus;
	set<int> dminus;
	forn(i,n-1) {
		if (s[i] == s[i+1]) {
			if (s[i]=='(') dplus.insert(i);
			else           dminus.insert(i);
		}
	}



	forn(_, q) {
		int p;
		cin >> p;
		--p;

		if (s[p] == '(') {
			s[p] = ')';

			suma -= 1;
			plus.erase(p);
			dplus.erase(p);
			dplus.erase(p-1);

			suma -= 1;
			minus.insert(p);
			if (p+1<n && s[p]==s[p+1])
				dminus.insert(p);

			if (p-1>=0 && s[p]==s[p-1])
				dminus.insert(p-1);

		} else {
			s[p] = '(';

			suma += 1;
			minus.erase(p);
			dminus.erase(p);
			dminus.erase(p-1);

			suma += 1;
			plus.insert(p);
			if (p+1<n && s[p]==s[p+1])
				dplus.insert(p);

			if (p-1>=0 && s[p]==s[p-1])
				dplus.insert(p-1);
		}




		bool ok = true;

		if (minus.count(0)) {
			ok = false;
		}

		if (plus.count(n-1)) {
			ok = false;
		}

		if (!dminus.empty()) {
			int primero = *dminus.begin();
			if (dplus.empty()) {
				ok = false;
			} else {
				int primero_otro = *dplus.begin();
				if (primero < primero_otro) {
					ok = false;
				}
			}
		}

		if (!dplus.empty()) {
			int ultimo = *dplus.rbegin();
			if (dminus.empty()) {
				ok = false;
			} else {
				int ultimo_otro = *dminus.rbegin();
				if (ultimo > ultimo_otro) {
					ok = false;
				}
			}
		}

		if ((suma%2+2)%2== 1) {
			ok = false;
		}
 

 		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	// vector<int> a(n);
	// forn(i,n) cin >> a[i];
	// sort(all(a));

	// vector<int> b(n);
	// forn(i,n) cin >> b[i];
	// sort(all(b));
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	forn(_,t) solve();
}
