#include <iostream>
#include <cstdint>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 100000;

int a [maxn];

vector<int> G[maxn];

int max_along[maxn];
int along[maxn];
bool vis[maxn];

void dfs(int v, int p) {
	vis[v] = true;

	along[v] = a[v] ? along[p] + 1 : 0;
	max_along[v] = max(max_along[p], along[v]);

	for (int u : G[v])
		if(u != p)
			dfs(u, v);
}

int main () {

	int n , m;

	cin >> n >> m;

	forn (i, n){
		cin >> a[i];
	}

	forn (i, n-1){
		int s ,f;
		cin >> s >> f;
		--s;--f;

		G[s].push_back(f);
		G[f].push_back(s);
	}

	dfs(0, 0);

	int solution = 0;

	forsn(v, 1, n){
		if(G[v].size() == 1){
			if(max_along[v] <= m)
				solution++;
		}
	}

	cout << solution << '\n';
}

