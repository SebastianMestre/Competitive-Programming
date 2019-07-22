#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); ++i)

constexpr int maxn = 200000;
constexpr int pot = 1 << 20;

vector<int> G[maxn];

int ST[pot];
bool lazy[pot];

bool visited[maxn] = {};
int idxlo[maxn];
int idxhi[maxn];

void pointupdate (int i) {
	i += pot/2;
	ST[i] = !ST[i];
	i /= 2;
	while(i){
		ST[i] = ST[i*2] + ST[i*2+1];
		i /= 2;
	}
}

void propagate(int i, int len){
	if(lazy[i]){
		lazy[i] = !lazy[i];
		ST[i] = len - ST[i];
		if(len > 1){
			lazy[i*2] = !lazy[i*2];
			lazy[i*2+1] = !lazy[i*2+1];
		}
	}
}

void rangeupdate (int i, int va, int vb, int qa, int qb) {
	propagate(i, vb-va);
	if(qa <= va and vb <= qb) {
		lazy[i] = !lazy[i];
		propagate(i, vb-va);
	} else if(vb <= qa or va >= qb) {
		return;
	} else {
		int m = (va+vb)/2;
		rangeupdate(i*2, va, m, qa, qb);
		rangeupdate(i*2+1, m, vb, qa, qb);
		ST[i] = ST[i*2] + ST[i*2+1];
	}
}

void vertexupdate (int i) {
	// range update [lo, hi)
	// where
	//   lo = idxlo[i]
	//   hi = idxhi[i]

	rangeupdate(1,0,pot/2, idxlo[i], idxhi[i]);
	return;
}

int query (int i, int va, int vb, int qa, int qb) {
	propagate(i, vb-va);
	if(qa <= va and vb <= qb) return ST[i];
	if(vb <= qa or va >= qb) return 0;
	int m = (va+vb)/2;
	return query(i*2, va, m, qa, qb) + query(i*2+1, m, vb, qa, qb);
}

int idx = 0;
void dfs (int v) {
	visited[v] = true;
	idxlo[v] = idx++;
	for(int x : G[v])
		if(not visited[x])
			dfs(x);
	idxhi[v] = idx;
}

int main () {
	int N;

	cin >> N;
	forn(i, N-1){
		int v;
		cin >> v;
		G[v-1].push_back(i+1);
	}

	dfs(0);

	// forn(i,N){
	// 	cerr << i+1 << " -> [" << idxlo[i] << ", " << idxhi[i] << ")\n";
	// }

	forn(i, N){
		int p;
		cin >> p;
		if(p){
			pointupdate(idxlo[i]);
		}
	}

	int Q;
	cin >> Q;

	forn(q, Q){
		string qt;
		int i;
		cin >> qt >> i;
		if(qt == "get")
			cout << query(1, 0, pot/2, idxlo[i-1], idxhi[i-1]) << '\n';
		else /* qt == "pow" */
			vertexupdate(i-1);
	}
}
