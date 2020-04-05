#include <iostream>
#include <cstdint>
#include <vector>
#include <queue>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 1000;

vector<int> G[maxn];
int ds [maxn];
int dt [maxn];
bool connected[maxn][maxn];

struct pii {
	int v;
	int d;
};

void bfs (int s, int* d, int n) {
	fill(d, d+n, INF);

	queue<pii> q;

	d[s] = 0;
	q.push({s, 0});
	
	while(not q.empty()){
		pii p = q.front();
		q.pop();

		if(p.d > d[p.v]) continue;

		for(int u : G[p.v]){
			if(p.d + 1 >= d[u]) continue;

			d[u] = p.d + 1;
			q.push({u, p.d+1});
		}
	}

}

int main () {

	int n, m, s, t;
	cin >> n >> m >>s >> t;

	--s;--t;

	forn(i,m){
		int a, b;
		cin >> a >> b;
		--a;--b;
		G[a].push_back(b);
		G[b].push_back(a);
		connected[a][b] = true;
		connected[b][a] = true;
	}

	bfs(s, ds, n);
	bfs(t, dt, n);

	int solution = 0;
	forn(u, n){
		forsn(v, u+1, n){
			if(connected[u][v]) continue;
			int nd = min(
				ds[v] + 1 + dt[u],
				ds[u] + 1 + dt[v]);

			if(nd >= ds[t]){
				solution += 1;

				// cerr << "Add edge: " << (u+1) << " -- " << (v+1) << '\n';
			}
		}
	}

	cout << solution << '\n';
}

