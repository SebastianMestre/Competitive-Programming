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


auto _seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rnd((unsigned)_seed);
mt19937_64 rnd64((ull)_seed);

vector<int> g[MAXN];
int n, m; 


int aleatorio() { return rnd(); }


vector<int> run() {
	int M = m == n ? m-1 : m;

	vector<int> ans;

	vector<int> rem(n);
	vector<int> perm(n);

	forn(i,n) rem[i] = perm[i] = i;

	auto elim = [&](int x) {
		int y = rem.back();

		int i = perm[x];
		int j = perm[y];

		rem[j] = x;
		perm[x] = j;

		rem[i] = y;
		perm[y] = i;
		
		rem.pop_back();
	};

	auto malo = [&](int u, int v) {
		return find(all(g[u]), v) != end(g[u]);
	};

	int ran = aleatorio() % rem.size();
	int pos = perm[ran];
	elim(pos);
	ans.push_back(pos);
	forn(i, M) {
		int pos_;

		int trials = 0;
		do {
			int ran = aleatorio() % rem.size();
			pos_ = rem[ran];
		} while (trials++ < 10 && malo(pos, pos_));
		if (malo(pos, pos_)) return {};

		// db(pos);

		pos = pos_;
		ans.push_back(pos);
		elim(pos);
	}

	if (m == n) {
		if (malo(ans.back(), ans[0]))
			return {};
		ans.pb(ans[0]);
	}

	return ans;
}

int main(){
	srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> m;

	forn(dongato, m) {
		int u, v; cin >> u >> v;
		u--; v--; g[u].pb(v); g[v].pb(u);
	}

	// Don Gato ^.^  ^w^
	vector<int> sol;
	forn(i, 10000) {
		sol = run();
		if (!sol.empty()) break;
	}

	if (sol.empty()) {
		cout << "-1\n";
	} else {
		forn(i, m) {
			cout << sol[i]+1 << ' ' << sol[i+1]+1 << '\n';
		}
	}

    return 0;
}
