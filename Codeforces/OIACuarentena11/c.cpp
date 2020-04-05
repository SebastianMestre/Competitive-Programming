#include <iostream>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 100000;
const int maxm = 100000;
vector<int> G[maxn];

int owner[maxn];
bool impossible = false;

vector<int> cover[3];

void dfs (int u, int c) {
	owner[u] = c;
	cover[c].push_back(u);

	for(int v : G[u]){
		if(owner[v] == c){ impossible = true; }
		if(!owner[v]){
			dfs(v, 3-c);
		}
	}
}

int main () {

	int n, m;
	cin >> n >> m;

	forn(i,m){
		int u,v;
		cin >> u >> v;
		--u;--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	forn(i,n) if(not G[i].empty()) if(!owner[i]) dfs(i, 1);

	if(impossible){
		cout << -1 << '\n';
		return 0;
	}

	forsn(i,1,3){
		cout << cover[i].size() << '\n';
		forn(j, cover[i].size()){
			cout << cover[i][j]+1 << ' ';
		}
		cout << '\n';
	}
}

