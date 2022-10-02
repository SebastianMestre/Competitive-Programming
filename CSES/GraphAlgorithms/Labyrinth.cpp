#include <vector>
#include <string>
#include <algorithm>
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

using pss = pair<short, short>;

const ll MAXN = 1e3+2;

char mapa[MAXN*MAXN];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	getchar(); /* endline */

	const int MH = n+1;
	const int MW = m+2;

	{int cu = m+2+1; forn(i,n) {
		fread(mapa+cu, 1, m+1, stdin);
		cu += MW;
	}}

	{int cu = 0; int const off = m+1; forn(i,n+2) {
		mapa[cu] = mapa[cu+off] = '#';
		cu += MW;
	}}

	{int const off = (n+1)*MW; forn(j,m+2) {
		mapa[j] = mapa[j+off] = '#';
	}}

	int first, last;
	forn(i, MH*MW) {
		if (mapa[i] == 'B') last  = i;
		if (mapa[i] == 'A') first = i;
	}

	mapa[last] = '.';

	vector<int> q_(MH*MW);
	int qs_ = 0;
	int qe_ = 0;

	auto pushq = [&](int p) { q_[qe_++] = p; };
	auto popq  = [&]() -> int { return q_[qs_++]; };
	auto emptyq = [&]() -> bool { return qs_ == qe_; };

	pushq(first);
	mapa[first] = '#';

	while (not emptyq()) {
		int u = popq();

		pair<int, char> vecinos[4] = {
			{u+MW, 'D'},
			{u-MW, 'U'},
			{u+1, 'R'},
			{u-1, 'L'},
		};

		for (auto vd : vecinos) {
			int v = vd.fst;
			char d = vd.snd;
			if (mapa[v] == '.') {
				pushq(v);
				mapa[v] = d;
			}
		}

		if (mapa[last] != '.') break;
	}

	if (mapa[last] == '.') {
		printf("NO\n");
		return 0;
	}

	auto unstep = [MW](int p, char d) -> int {
		if (d == 'D') return p-MW;
		if (d == 'U') return p+MW;
		if (d == 'R') return p-1;
		if (d == 'L') return p+1;
	};

	string path;
	path.reserve(n+m);
	int pos = last;
	while (pos != first) {
		char d = mapa[pos];
		path.pb(d);
		pos = unstep(pos, d);
	}

	reverse(all(path));
	printf("YES\n%d\n%s\n", sz(path), path.c_str());

	return 0;
}
