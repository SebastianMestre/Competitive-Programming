#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 1000;
const int maxk = 5;
vector<int> G[maxn];
vector<int> S[maxk];
int pos[maxk][maxn];

bool vis[maxn];
int DP[maxn];
int dfs(int x){
	if(DP[x]) return DP[x];
	int res = 0;
	for(int y : G[x]){
		res = max(res, dfs(y));
	}
	return DP[x] = res+1;
}

int main () {
	int n , k;
	cin >> n >> k;


	forn(i, k){
		forn(j,n){
			int a;
			cin >> a;
			--a;
			S[i].push_back(a);
			pos[i][a] = j;
		}
	}

	forn(u,n){
		forn(v,n){
			if(u==v) continue;

			bool isbefore = true;
			forn(s,k){
				if(pos[s][v] < pos[s][u]){
					isbefore = false;
					break;
				}
			}

			if(not isbefore) continue;

			G[u].push_back(v);
		}
	}

	int maxv = 1;
	forn(i,n){
		maxv = max(maxv, dfs(i));
	}

	cout << maxv << '\n';
}

