#include <iostream>
#include <cassert>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define fornn(i,s,n) for(int i = s; i < int(n); ++i)
#define forr(i,n) for(int i = n; i--;)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

constexpr int maxn = 1e5;
constexpr int maxa = 2e5;

int a[maxn];
int k[maxa];
int k0[maxa];

int main () {
	int n;
	cin >> n;

	forn(i,n) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << "N\n";
		return 0;
	}

	forn(i,n) {
		k[a[i]] += 1;
	}

	forn(i, maxa) {
		k[i+1] += k[i] / 2;
		k[i] %= 2;
	}

	int pc = 0;
	forn(i, maxa)
		pc += k[i] != 0;

	if (pc > 2) {
		cout << "N\n";
		return 0;
	}

	if (pc == 2) {
		cout << "Y\n";
		return 0;
	}

	assert(pc != 0);
	assert(pc == 1);

	if (k[0]) {
		cout << "N\n";
		return 0;
	}

	cout << "Y\n";
	return 0;
}
