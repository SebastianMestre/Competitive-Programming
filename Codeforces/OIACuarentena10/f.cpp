#include <iostream>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

struct edge {
	int v;
	int i;
};

const int maxn = 100;
const int maxm = maxn*(maxn-1)/2;
bool paved[maxm];
vector<edge> G[maxn];
bool flipped[maxn];
int n,m;
int unpaved;
int must_flip[maxn];
int must_nothing[maxn];

bool bt (int v) {
	if(v==n){
		return unpaved == 0;
	} else {

		if(!must_flip[v]){
			// try nothing
			for(auto e : G[v]){
				must_flip[e.v] += int(!paved[e.i]);
				must_nothing[e.v] += int(paved[e.i]);
			}

			if(bt(v+1)) return true;

			// failed, roll back
			for(auto e : G[v]){
				must_flip[e.v] -= int(!paved[e.i]);
				must_nothing[e.v] -= int(paved[e.i]);
			}
		}

		if(!must_nothing[v]){
			// try flipping
			flipped[v] = true;
			for(auto e : G[v]){
				paved[e.i] = !paved[e.i];
				unpaved += paved[e.i] ? -1 : 1;
			}

			for(auto e : G[v]){
				must_flip[e.v] += int(!paved[e.i]);
				must_nothing[e.v] += int(paved[e.i]);
			}

			if(bt(v+1)) return true;

			// failed, roll back
			for(auto e : G[v]){
				must_flip[e.v] -= int(!paved[e.i]);
				must_nothing[e.v] -= int(paved[e.i]);
			}

			for(auto e : G[v]){
				paved[e.i] = !paved[e.i];
				unpaved += paved[e.i] ? -1 : 1;
			}
			flipped[v] = false;
		}

		return false;
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	unpaved = m;
	forn(i,m){
		int u,v;
		int p;
		cin>>u>>v>>p;
		--u;--v;
		unpaved -= p;
		paved[i] = p;
		G[u].push_back({v,i});
		G[v].push_back({u,i});
	}

	forn(i,n){
		break;
		if(G[i].size() == 0){
			must_nothing[i] = 1;
		}
	}

	bool can = bt(0);

	if(not can){
		cout << "Impossible\n";
		return 0;
	} else {
		int flipc = 0;
		forn(i,n) flipc += int(flipped[i]);
		cout << flipc <<'\n';
		forn(i,n){ if(flipped[i]) cout << i+1 << ' ';}
		cout << '\n';
	}
}

