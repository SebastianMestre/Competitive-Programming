#include <iostream>
#include <cstdint>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

using ll = long long;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 200000;

int c[maxn];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	forn (i, n){
		cin >> c[i];
	}

	forn (i, n){
		int x;
		cin >> x;
		c[i] -= x;
	}

	sort(c, c+n);

	ll good_pairs = 0;

	int j = n;
	forn(i,n){
		int x = -c[i];
		while(j>0 && c[j-1] > x) --j;

		int howmany = n - j;
		if(j < i) howmany -= 1;

		good_pairs += howmany;
		// cerr << "* " << howmany << '\n';
	}


	cout << good_pairs / 2 << '\n';
}

