#include <iostream>
#include <cstdint>
#include <queue>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;
using ll = long long;

constexpr ll INF = 1ll<<50; //
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 1000;

struct edge {
	int v;
	ll d;

	bool operator < (edge const& o) const {
		return o.d < d;
	}
};

vector<edge> G1[maxn];
vector<edge> G2[maxn];

ll DV[maxn][maxn];
ll DT[maxn];

int c[maxn];
int t[maxn];

void dijk (vector<edge>* G, ll* D, int n, int s) {
	fill(D,D+n,INF);

	priority_queue<edge> pq;

	D[s] = 0;
	pq.push({s, 0});

	while(not pq.empty()){
		edge p = pq.top();
		pq.pop();

		if(D[p.v] < p.d) continue;

		for(edge e : G[p.v]){
			if(D[e.v] <= p.d + e.d) continue;

			D[e.v] = p.d + e.d;
			pq.push({e.v, D[e.v]});
		}
	}
}

int main () {

	int n, m;
	cin >> n >> m;

	int x, y;
	cin >> x >> y;

	--x; --y;

	forn(i,m){
		int u,v,w;
		cin >> u >> v >> w;
		--u;--v;

		G1[u].push_back({v,w});
		G1[v].push_back({u,w});
	}

	forn(i,n){
		cin >> t[i] >> c[i];
	}

	forn(i,n){
		dijk(G1, DV[i], n, i);

		forn(j,n){
			if(i==j)continue;
			if(DV[i][j] > t[i]) continue;

			G2[i].push_back({j, c[i]});
		}
	}

	dijk(G2, DT, n, x);

	cout << (DT[y]==INF?-1:DT[y]) << '\n';

}

