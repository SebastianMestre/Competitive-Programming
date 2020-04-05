#include <iostream>
#include <vector>
#include <cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)

// Solution in O(N^(3/2)). Gives TLE

using namespace std;

constexpr int maxn = 200000;
int N;

int dquery (int v) {
	int result;
	cout << "d " << v << '\n' << flush;
	cin >> result;
	if(result == -1) exit(0);
	return result;
}

int squery (int v) {
	int result;
	cout << "s " << v << '\n' << flush;
	cin >> result;
	if(result == -1) exit(0);
	return result;
}

void answer (int v) {
	cout << "! " << v << '\n' << flush;
	exit(0);
}

int parent[maxn+1];
bool visited[maxn+1];
vector<int> G[maxn+1];
vector<int> C[maxn+1];
int hDP[maxn+1];
int height (int v) {
	return hDP[v];
}
void init(int v){
	visited[v] = true;

	hDP[v] = 0;
	for(int u : G[v]){
		if(not visited[u]){
			C[v].push_back(u);
			init(u);
			parent[u] = v;
			hDP[v] = max(hDP[v], hDP[u]);
		}
	}
	hDP[v]++;
}
int parentall (int v, int& d) {
	do{
		//cerr << "[ v: " << v << " d: " << d << " ]\n";

		if(d == 0)
			answer(v);

		int c = 0;
		int succ = -1;
		for(int u : C[v]){
			//cerr << "[loop u: "<<u<<" d: "<<d-1<<"]\n";
			if(height(u) >= d){
				c++;
				succ = u;
			}
		}

		if(c == 0) {
			answer(v);
		}
		assert(("No good children means we took the wrong path", c != 0));

		if(c >= 2) { return v; }

		v = succ;
		d -= 1;

	} while(true);
}

int main () {
	cin >> N;
	forn(i,N-1){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	init(1);

	int v = 1;

	int d = dquery(v);
	while(true){
		v = parentall(v, d);

		v = squery(v);
		d -= 1;
	}
}
