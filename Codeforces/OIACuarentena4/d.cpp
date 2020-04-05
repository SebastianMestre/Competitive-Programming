#include <iostream>
#include <cstdint>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

struct pii {
	int l, r;

	bool operator < (pii const& o) const {
		return l < o.l;
	}	
};

const int maxn = 200000;

pii a[maxn+1];

int main () {

	int n, h;
	cin >> n >> h;

	forn(i,n){
		cin >> a[i].l >> a[i].r;
	}
	a[n].l = int(2e9);
	a[n].r = int(2e9) + 1;

	sort(a, a+n);
	
	int hj = h;
	int best_dist = 0;
	for(int i = 0, j = 0; i < n; ++i){
		while((a[j+1].l - a[j].r) < hj){
			hj -= (a[j+1].l - a[j].r);
			++j;
		}

		int dist = (a[j].r - a[i].l) + hj;
		best_dist = max(best_dist, dist);

		hj += (a[i+1].l - a[i].r);
	}

	std::cout << best_dist << '\n';
}

