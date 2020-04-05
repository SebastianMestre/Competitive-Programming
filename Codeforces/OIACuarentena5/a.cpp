#include <iostream>
#include <cstdint>
#include <vector>
#include <queue>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

using ll = long long;
struct edge {
	int v;
	ll d;

	bool operator < (edge const& o) const {
		return o.d < d;
	}
};

constexpr ll INF = 1ll<<60; //
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 100000;
vector<edge> G[maxn];
int a[maxn];
int n, m, k;
ll D[maxn];
bool storage[maxn];

void dijk () {

	priority_queue<edge> pq;

	forn(i,n){
		D[i] = INF;
	}

	forn(i,k){
		D[a[i]] = 0;
		pq.push({a[i], 0});
	}

	while(not pq.empty()){
		edge e = pq.top();
		pq.pop();

		if(D[e.v] < e.d) continue;

		D[e.v] = e.d;

		for(edge f : G[e.v]){
			if(D[f.v] <= e.d + f.d)
				continue;

			D[f.v] = e.d + f.d;
			pq.push({f.v, e.d+f.d});
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	forn(i, m){
		int s, f, d;
		cin >> s >> f >> d;
		--s; --f;
		G[s].push_back({f, d});
		G[f].push_back({s, d});
	}

	forn(i,k){
		cin >> a[i];
		--a[i];
		storage[a[i]] = true;
	}

	if(k==0){
		cout << -1 <<'\n';
		return 0;
	}

	dijk();

	int solution= -1;
	ll dsol = INF;
	forn(i, n){
		if(storage[i]) continue;
		if(D[i] == INF) continue;

		if(D[i] < dsol){
			solution = i + 1;
			dsol = D[i];
		}
	}

	cout << (solution==-1?-1:dsol) << '\n';
}

