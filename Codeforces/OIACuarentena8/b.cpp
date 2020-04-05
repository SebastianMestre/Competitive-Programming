#include <iostream>
#include <cstdint>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

int main () {

	int n, m;
	cin >> n >> m;

	int maxt = 0;
	forn(a, min(n, m/2)+1){
		int ni = n - a;
		int mi = m - a - a;

		int b = min(mi, ni/2);

		int ti = a+b;

		maxt = max(maxt, ti);
	}

	cout << maxt << '\n';

}

