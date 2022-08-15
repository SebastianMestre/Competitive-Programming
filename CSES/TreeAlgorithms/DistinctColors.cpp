#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <iterator>
#include <stack>

using namespace std;

#define forr(i,s,n) for(int i{s}; i < int{n}; ++i)
#define forn(i,n) forr(i,0,n)

using pii = pair<int,int>;

constexpr int maxn = 2e5;
vector<int> G[maxn];
int c[maxn];

int lvl[maxn];
bool visited[maxn];
void dfs(int u, int l) {
	vector<pii> S;
	S.reserve(maxn);
	S.push_back({u, l});
	while(!S.empty()) {
		auto [u,l] = S.back(); S.pop_back();
		visited[u] = true;
		lvl[u] = l;
		for (int v : G[u])
			if (!visited[v])
				S.push_back({v, l+1});
	}
}

using Set = set<int>;
Set m[maxn];
int m_idx[maxn];
int join(int i, int j) {
	if (m[i].size() < m[j].size())
		swap(i, j);
	for (int x : m[j]) m[i].insert(x);
	return i;
}
void add_edge(int u, int v) {
	assert(lvl[u] < lvl[v]);
	m_idx[u] = join(m_idx[u], m_idx[v]);
}


int by_level[maxn];
int component_size[maxn];


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

	dfs(0, 1);

	forn(u,n)by_level[u]=u;
	sort(by_level, by_level+n, [](int u, int v){ return lvl[u] > lvl[v]; });

	forn(u,n)m[u].insert(c[u]);
	forn(u,n)m_idx[u]=u;

	forn(i,n){
		int u = by_level[i];
		for (int v : G[u]) {
			if (lvl[v] < lvl[u]) continue;
			add_edge(u, v);
		}
		component_size[u] = m[m_idx[u]].size();
	}

	forn(u,n) cout << component_size[u] << ' ';
	cout << '\n';

}
