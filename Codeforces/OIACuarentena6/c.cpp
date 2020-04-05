#include <iostream>
#include <cstdint>
#include <vector>
#include <queue>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

const int maxn = 100000;
constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

vector<int> G[maxn];

bool seen[maxn];

int main () {

	int n, m;
	cin >> n >> m;

	forn(i, m){
		int u,v;
		cin >> u >> v;
		--u;--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<int> sequence;
	priority_queue<int> minus_candidates;
	
	int v = 0;
	seen[v] = true;
	forn(i,n){
		sequence.push_back(v);

		for(int u : G[v]){
			if(not seen[u]){
				minus_candidates.push(-u);
				seen[u] = true;
			}
		}

		if(not minus_candidates.empty()){
			v = -minus_candidates.top();
			minus_candidates.pop();
		}
	}

	for(int x : sequence){
		cout << (x+1) << ' ';
	}
	cout << '\n';
}

