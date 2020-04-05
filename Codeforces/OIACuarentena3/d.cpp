#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

const int maxn = 500;
bool railway[maxn][maxn];
set<int> G[maxn];
bool vis[maxn];

struct pii {
	int i, t;
};

int main () {
	int n, m;
	cin >> n >> m;

	forn(i, m){
		int a, b;
		cin >> a >> b;
		--a; --b;
		railway[a][b] = true;
		railway[b][a] = true;
		G[a].insert(b);
		G[b].insert(a);
	}

	if(not railway[0][n-1]){
		queue<pii> Q;
		Q.push({0, 0});
		while(not Q.empty()){
			pii v = Q.front();
			Q.pop();

			if(v.i == n-1){
				cout << v.t << '\n';
				return 0;
			}

			vis[v.i] = true;

			for(int u : G[v.i]){
				if(!vis[u]){
					Q.push({u, v.t+1});
					vis[u] = true;
				}
			}

		}

		cout << "-1\n";
		return 0;
	} else {

		queue<pii> Q;
		Q.push({0, 0});
		while(not Q.empty()){
			pii v = Q.front();
			Q.pop();

			if(v.i == n-1){
				cout << v.t << '\n';
				return 0;
			}

			vis[v.i] = true;

			for(int u = 0; u < n; ++u){
				if(G[v.i].count(u) != 0)
					continue;

				if(!vis[u]){
					Q.push({u, v.t+1});
					vis[u] = true;
				}
			}

		}
		cout << "-1\n";
		return 0;

	}
}
