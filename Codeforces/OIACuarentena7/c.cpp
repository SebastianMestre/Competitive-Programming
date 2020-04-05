#include <iostream>
#include <cstdint>
#include <queue>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 100000;
int cost[maxn];

int DS[100][maxn];

struct edge {
	int v, d;
	bool operator < (edge const& o) const {
		return o.d < d;
	}	
};


vector<int> G[maxn];

void dij (vector<int> source, int* D, int n) {

	queue<edge> pq;

	fill(D, D+n, INF);

	for(int s : source){
		pq.push({s, 0});
		D[s] = 0;
	}

	while(not pq.empty()){
		edge e = pq.front();
		pq.pop();
		
		if(D[e.v] < e.d) continue;

		for(int u : G[e.v]){
			if(D[u] <= e.d + 1) continue;

			D[u] = e.d + 1;
			pq.push({u, D[u]});
		}
	}
}

vector<int> sources[100];
int main () {
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	forn(i,n){
		int p;
		cin >> p;
		sources[p-1].push_back(i);
	}
	forn(i,m){
		int a,b;
		cin >> a >> b;
		--a;--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	forn(i,k){
		dij(sources[i], DS[i], n);
	}
	vector<int> v(k);
	forn(i,n){
		forn(p,k){
			v[p] = DS[p][i];
		}
		sort(v.begin(), v.end());
		int sum = 0;
		forn(p,s){ sum += v[p]; }
		cout << sum << ' ';
	}
	cout << '\n';
}

