#include <iostream>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define fornn(i,s,n) for(int i = s; i < int(n); ++i)
#define forr(i,n) for(int i = n; i--;)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<27;
constexpr int MOD = 1000000007; // 1e9+7

constexpr int maxn = 100;

struct edge {
	int v;
	int w;
};

int main () {
	int n;
	cin >> n;

	forn(i,n) {
		if (cin.peek() == '*') {
			int v;
			cin >> v;
			G[u].push_back({v, INF});
			Ginf[u].push_back(v);
		} else {
			int m;
			cin >> m;
			forn(j, m) {
				int v;
				cin >> v;
				G[u].push_back({v, 1});
			}
		}
	}

}
