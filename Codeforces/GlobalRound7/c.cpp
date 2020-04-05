#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 998244353; 

struct pii {
	int val, idx;
	bool operator < (pii const& o) const {
		return val < o.val;
	}
};

int main () {

	int n, k;
	cin >> n >> k;

	vector<pii> v(n);
	forn(i, n){
		cin >> v[i].val;
		v[i].idx = i;
	}

	sort(v.begin(), v.end());

	vector<pii> biggest(k);
	long long sum = 0;
	forn(i, k){
		biggest[i] = v[i+n-k];
		sum += biggest[i].val;
		swap(biggest[i].val, biggest[i].idx);
	}

	sort(biggest.begin(), biggest.end());

	long long ways = 1;

	forsn(i,1, k){
		long long cuts = biggest[i].val - biggest[i-1].val;
		ways = (ways * cuts) % MOD;
	}

	cout << sum << ' ' << ways <<'\n';
	
}

