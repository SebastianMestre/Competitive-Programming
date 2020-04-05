#include <iostream>
#include <queue>
#include <vector>
#include <iostream>

// STATUS: WA

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

const int maxnm = 1000;
const int maxk = 40;

int color[maxnm][maxnm];
int D[maxk][maxnm][maxnm];

struct edge {
	pair<int, int> pos;
	int len;

	bool operator < (edge const& o) const {
		return o.len < len;
	}
};

vector<pair<int, int>> idces[maxk];

int N, M, K;

const int INF = 1e4;
void dijk (int k) {

	priority_queue<edge> PQ;

	forn(r, N){
		forn(c, M){
			D[k][r][c] = INF;
		}
	}

	PQ.push({{-1,-1}, 0});
	
		// cout << "dij" << k <<'\n';
	while(!PQ.empty()){

		edge next = PQ.top();
		PQ.pop();

		// cout << "pos " << next.pos.first << ' ' << next.pos.second << '\n';

		std::vector<pair<int, int>> neighbors;

		if(next.pos.first == -1){
			neighbors = idces[k];
		} else {
			if(next.len > D[k][next.pos.first][next.pos.second])
				continue;

			D[k][next.pos.first][next.pos.second] = next.len;

			int dr[] = {1,0,-1,0};
			int dc[] = {0,1,0,-1};
			forn(i,4){
				int r = next.pos.first + dr[i];
				int c = next.pos.second + dc[i];
				if(r >= 0 && r < N){
					if(c >= 0 && c < M){
						neighbors.push_back({r, c});
					}
				}
			}

		}

		for(pair<int, int> const& p : neighbors) {
			int d = next.len + 1;
			int& dr = D[k][p.first][p.second];
			if(d < dr){
				dr = d;
				PQ.push({p, d});
			}
		}
	}
}

int main () {
	cin >> N >> M >> K;

	forn(r,N){
		forn(c,M){
			cin >> color[r][c];
			color[r][c] -= 1;

			idces[color[r][c]].push_back({r,c});
		}
	}

	forn(k,K){
		dijk(k);
	}

	forn(i,N){
		forn(j,M){
			cout << D[0][i][j] << ' ';
		}
		cout << '\n';
	}

	int Q;
	cin >> Q;

	forn(q,Q){
		int r0, c0, r1, c1;
		cin >> r0 >> c0 >> r1 >> c1;

		--r0; --c0; --r1; --c1;

		int mind = abs(r0-r1) + abs(c0-c1);

		forn(k, K){
			mind = min(mind, D[k][r0][c0] + D[k][r1][c1] - 1);
		}

		cout << mind << '\n';
	}
}
