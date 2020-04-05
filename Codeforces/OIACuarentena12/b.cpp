#include <iostream>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 2000;
vector<int> G[maxn];

int h[maxn];
int dfs(int x){
	if(h[x]) return h[x];
	int maxv = 0;
	for(int y : G[x]){
		maxv = max(maxv, dfs(y));
	}
	return h[x] = maxv + 1;
}

int main () {

	int n;
	cin >> n;

	forn(i,n){
		int jefe;
		cin >> jefe;
		jefe -= 1;
		if(jefe>=0)
		G[jefe].push_back(i);
	}

	int maxv = 0;
	forn(i,n){
		maxv = max(maxv, dfs(i));
	}

	cout << maxv << '\n';
}

