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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> arr(n); forn(i,n) cin >> arr[i];

	set<pii> s1;
	set<pii> s2;

	auto balancear = [&]() {
		while (s1.size() < s2.size()) {
			s1.insert(*s2.begin());
			s2.erase(*s2.begin());
		}
		while (s1.size() > s2.size() + 1) {
			s2.insert(*s1.rbegin());
			s1.erase(*s1.rbegin());
		}
	};

	auto mediana = [&]() {
		return s1.rbegin()->first;
	};

	auto sep = "";
	int j = 1;
	s1.insert({arr[0], 0});
	forn(i,n) {

		for (; j < n && j-i < k; j++) {
			auto& mitad = (s1.empty() || arr[j] < mediana()) ? s1 : s2;
			mitad.insert({arr[j], j});
			balancear();
		}

		if (j-i == k) {

			int m = mediana();

			cout << exchange(sep, " ") << m;

			s1.erase({arr[i], i});
			s2.erase({arr[i], i});
			balancear();
		}
	}
	cout << "\n";

    return 0;
}
