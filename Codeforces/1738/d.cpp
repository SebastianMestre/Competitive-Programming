#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=int(a);--i)
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

vector<vector<int>> apariciones;

void solve() {
	int n;
	cin >> n;

	vector<int> b(n);
	forn(i,n) cin >> b[i];
	b.insert(b.begin(), 1<<30);

	apariciones.clear();
	apariciones.resize(n+2);

	forr(i,1,n+1){
		apariciones[b[i]].pb(i);
	}

	const int GT = 1, LE = 0;

	int le_counter = 0;
	vector<int> orden;
	queue<pii> q;
	vector<bool> vis(n+1, false);
	q.push({0, LE});
	q.push({n+1, GT});
	while (not q.empty()) {
		auto [j, grupoj] = q.front(); q.pop();
		orden.pb(j);
		if (grupoj == LE) le_counter++;
		for (int i : apariciones[j]) {
			if (not apariciones[i].empty()) continue;
			if (vis[i]) continue;
			int grupoi = 1-grupoj;
			q.push({i, grupoi});
			vis[i] = true;
		}
		for (int i : apariciones[j]) {
			if (apariciones[i].empty()) continue;
			if (vis[i]) continue;
			int grupoi = 1-grupoj;
			q.push({i, grupoi});
			vis[i] = true;
		}
	}


	int cutoff = le_counter-1;
	cout << cutoff << '\n';

	orden.erase(orden.begin(), orden.begin()+2);
	forn(i, orden.size()) {
		if (i) cout << ' ';
		cout << orden[i];
	}
	cout << '\n';
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t; cin >> t;
	forn(_,t) solve();
    
    return 0;
}
