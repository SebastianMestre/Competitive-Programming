#include <iostream>
#include <set>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 200000;
const int maxm = 200000;

int p[maxn];
int a[maxn];
int b[maxn];

struct shirt {
	int i;
	int p;
	int a;
	int b;

	bool operator < (shirt const& o) const {
		return p!=o.p ? p < o.p : i < o.i;
	}
};

// first one is unused
set<shirt> color[4];

int main () {
	int n;
	cin >> n;
	forn(i,n){ cin >> p[i]; }
	forn(i,n){ cin >> a[i]; }
	forn(i,n){ cin >> b[i]; }
	forn(i,n){
		shirt s = {i, p[i], a[i], b[i]};
		forsn(j,1,4) if(s.a == j || s.b == j) color[j].insert(s);
	}
	int m;
	cin >> m;
	forn(i,m){
		int c;
		cin >> c;

		auto it = color[c].begin();

		if(it == color[c].end()) {
			cout << -1 << ' ';
			continue;
		}

		shirt s = *it;

		color[c].erase(it);
		if(s.a != c) color[s.a].erase(s);
		if(s.b != c) color[s.b].erase(s);

		cout << s.p << ' ';
	}

	cout << '\n';

}

