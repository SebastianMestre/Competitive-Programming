#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cassert>
#include <iterator>
#include <stack>

using namespace std;

#define forr(i,s,n) for(int i{s}; i < int{n}; ++i)
#define forn(i,n) forr(i,0,n)

using pii = pair<int,int>;

constexpr int maxn = 2e5;

vector<int> G[maxn];
unordered_set<int> hist[maxn];
int c[maxn];
int ans[maxn];

void dfs(int u, int par) {

	for (int v : G[u]) {

		if (v == par) continue;

		dfs(v, u);

		if (hist[u].size() < hist[v].size())
			swap(hist[u], hist[v]);

		for (int c : hist[v])
			hist[u].insert(c);

		// hist[v].clear();
	}

	ans[u] = hist[u].size();
}

int main() {
	int n;

	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> n;
		forn(i,n) cin >> c[i];
		forn(i,n-1) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}

	forn(u, n) hist[u].insert(c[u] ^ 985298257);
	dfs(0, -1);
	forn(u, n) cout << ans[u] << (u==n-1?"\n":" ");

	cout << '\n';

}
