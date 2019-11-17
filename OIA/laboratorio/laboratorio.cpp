#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;

constexpr int maxn = 300000;
int usize [maxn];
int urepr [maxn];

int uleng;

bool entrada[maxn];
bool bloqueado[maxn];

int N;
int M;
int P;

void init () {
	forn(i,uleng) urepr[i] = i;
	forn(i,uleng) usize[i] = 1;
}

int find (int i) {
	if(urepr[i] == i) return i;
	return urepr[i] = find(urepr[i]);
}

int find_size (int i) {
	return usize[find(i)];
}

void join (int i, int j) {
	int ri = find(i);
	int rj = find(j);
	if(ri == rj) return;

	urepr[ri] = rj;
	usize[rj] += usize[ri];
	usize[ri] = 0;
}

int idx (int x, int y) {
	return x * N + y;
}

struct pt { int x, y; };

void try_join (vector<string> const& mapa, pt a, pt b) {
	if(a.x < 0) return;
	if(a.x >= M) return;
	if(a.y < 0) return;
	if(a.y >= N) return;

	if(b.x < 0) return;
	if(b.x >= M) return;
	if(b.y < 0) return;
	if(b.y >= N) return;

	if(bloqueado[idx(a.x, a.y)]) return;
	if(bloqueado[idx(b.x, b.y)]) return;

	join(idx(a.x, a.y), idx(b.x, b.y));
}

vector<int> laboratorio(vector<string> mapa, vector<int> perrosF, vector<int> perrosC) {
	N = mapa.size();
	M = mapa[0].size();
	P = perrosC.size();
	uleng = N * M;
	init();

	reverse(perrosC.begin(), perrosC.end());
	reverse(perrosF.begin(), perrosF.end());


	vector<pt> entradas;

	forn(y, N){
		forn(x, M){
			if(mapa[y][x] == '#')
				bloqueado[idx(x,y)] = true;
			if(mapa[y][x] == 'E'){
				entradas.push_back({x,y});
				entrada[idx(x,y)] = true;
			}
		}
	}

	forn(i, entradas.size()-1){
		join(
			idx(entradas[i].x, entradas[i].y),
			idx(entradas[i+1].x, entradas[i+1].y));
	}

	int entradas_tapadas = 0;
	forn(i, P){
		int x = perrosC[i];
		int y = perrosF[i];
		int v = idx(x,y);
		bloqueado[v] = true;
		if(entrada[v]) entradas_tapadas++;
	}

	forn(y, N){
		forn(x, M){
			try_join(mapa, {x, y}, {x-1, y});
			try_join(mapa, {x, y}, {x+1, y});
			try_join(mapa, {x, y}, {x, y-1});
			try_join(mapa, {x, y}, {x, y+1});
		}
	}

    vector<int> ret;

	forn(i, P) {
		ret.push_back(find_size(idx(entradas[0].x, entradas[0].y)) - entradas_tapadas);

		int x = perrosC[i];
		int y = perrosF[i];
		int v = idx(x,y);
		bloqueado[v] = false;
		if(entrada[v]) entradas_tapadas--;

		try_join(mapa, {x, y}, {x-1, y});
		try_join(mapa, {x, y}, {x+1, y});
		try_join(mapa, {x, y}, {x, y-1});
		try_join(mapa, {x, y}, {x, y+1});
	}

	assert(entradas_tapadas == 0);

	reverse(ret.begin(), ret.end());

    return ret;
}


#ifndef EVAL
    #include <iostream>

    int main() {
        int N,M,P;
        cin >> N >> M >> P;
        vector<string> mapa;
        mapa.reserve(N);
        for (int i=0;i<N;i++) {
            string fila; cin >> fila;
            mapa.push_back(fila);
        }
        vector<int> perrosF, perrosC;
        perrosF.reserve(P);
        perrosC.reserve(P);
        for (int i=0;i<P;i++) {
            int f,c; cin >> f >> c;
            perrosF.push_back(f);
            perrosC.push_back(c);
        }
        vector<int> ret = laboratorio(mapa, perrosF, perrosC);
        for (int i=0;i<int(ret.size());i++) {
            if (i > 0)
                cout << " ";
            cout << ret[i];
        }
        cout << endl;
    }
#endif
