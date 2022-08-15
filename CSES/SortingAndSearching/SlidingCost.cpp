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

struct S {
	set<pii> data;
	ll suma = 0;
	int size() { return data.size(); }
};

void add(S& s, pii p) {
	s.data.insert(p);
	s.suma += p.fst;
}

void rem(S& s, pii p) {
	if (!s.data.count(p)) return;
	s.data.erase(p);
	s.suma -= p.fst;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<pii> arr(n); forn(i,n) { cin >> arr[i].fst; arr[i].snd = i; }

	S s1, s2;

	auto balancear = [&]() {
		while (s1.size() < s2.size()) {
			auto p = *s2.data.begin();
			add(s1, p);
			rem(s2, p);
		}
		while (s1.size() > s2.size() + 1) {
			auto p = *s1.data.rbegin();
			add(s2, p);
			rem(s1, p);
		}
	};

	auto mediana = [&]() {
		return s1.data.rbegin()->first;
	};

	auto sep = "";
	int j = 1;
	add(s1, arr[0]);
	forn(i,n) {

		for (; j < n && j-i < k; j++) {
			auto& mitad = (s1.data.empty() || arr[j].fst < mediana()) ? s1 : s2;
			add(mitad, arr[j]);
			balancear();
		}

		if (j-i == k) {
			ll m = mediana();
			ll c1 = m * s1.size() - s1.suma;
			ll c2 = s2.suma - m * s2.size();
			cout << exchange(sep, " ") << c1+c2;
			rem(s1, arr[i]);
			rem(s2, arr[i]);
			balancear();
		}
	}
	cout << "\n";

    return 0;
}
