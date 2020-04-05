#include <iostream>
#include <cstdint>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int stlen = 1<<19;
const int stsize = 1<<20;

long long sta[stsize];
long long stb[stsize];

using ll = long long;

void update (ll* st, int i, ll x, ll cap){
	i += stlen;
	st[i] += x;
	st[i] = min(st[i], cap);
	while(i/=2){
		st[i] = st[i*2] + st[i*2+1];
	}
}

int qa, qb;
ll query_ (ll* st, int i, int a, int b){
	if(qa <= a && b <= qb) return st[i];
	if(b <= qa || qb <= a) return 0;

	int m = (a+b)/2;
	return query_(st, i*2, a, m) + query_(st, i*2+1, m, b);
}
ll query (ll* st, int a, int b){
	qa=a;qb=b;
	return query_(st, 1, 0, stlen);
}

int main () {

	int n,k,a,b,q;
	cin >> n >> k >> a >> b >> q;

	forn(i, q){
		int t;
		cin >> t;

		if(t == 1){
			int di, ai;
			cin >> di >> ai;

			--di;

			update(sta, di, ai, a);
			update(stb, di, ai, b);

		} else {
			int pi;
			cin >> pi;

			--pi;

			ll before = query(stb, 0, pi);
			ll after = query(sta, pi+k, n);

			cout << before + after << '\n';

		}
	}

}

