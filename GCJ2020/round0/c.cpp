#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define forn(i,n) for(int i =0; i <int(n);++i)
#define forsn(i,s,n) for(int i =s; i <int(n);++i)

const int maxn = 1000;
vector<int> G[maxn];

using pii = pair<int,int>;

bool overlaps (pii a, pii b){
	return a.first < b.second && b.first < a.second;
}

int other(int c){
	return 3-c;
}

int color[maxn];
bool can_color = true;
void dfs (int v, int c) {
	color[v] = c;
	for(int u : G[v]){
		if(color[u] == c){
			can_color = false;
			return;
		}

		if(not color[u]){
			dfs(u,other(c));
		}

		if(not can_color) return;
	}
}

int main () {

	int t;
	cin >> t;

	forn(ti,t){
		int n;
		cin >> n;

		can_color = true;
		forn(i,n){
			color[i] = 0;
			G[i].clear();
		}

		vector<pair<int,int>> vp;
		forn(i,n){
			int s,e;
			cin >> s >> e;
			vp.push_back({s,e});
		}

		forn(i,n){
			forsn(j,i+1,n){
				if(overlaps(vp[i],vp[j])){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}

		forn(i,n){
			if(not can_color) break;
			if(not color[i]) dfs(i, 1);
		}

		cout << "Case #" << (ti+1) << ": ";
		if(can_color){
			forn(i,n){
				cout << (color[i] == 1 ? 'C' : 'J');
			}
		}else{
			cout << "IMPOSSIBLE";
		}
		cout << '\n';

	}
}
