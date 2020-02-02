#include <iostream>
#include <map>

#define forn(i,n) for(int i = 0; i<int(n); ++i)
constexpr int maxn = 300000;
constexpr int stlen = 1 << 20;
constexpr int stbuf = 1 << 21;
int current_pos[maxn];
int ST[stbuf];
int N, M;

using namespace std;

int _a, _b;
int _query (int i, int a, int b) {
	if(_a <= a && b <= _b) return ST[i];
	if(b <= _a || _b <= a) return 0;
	int m = (a+b)/2;
	return _query(i*2,a,m) + _query(i*2+1,m,b);
}
int query (int a, int b) {
	_a = a; _b = b;
	return _query(1, 0, stlen);
}

void update (int i, int x) {
	i+=stlen;
	ST[i] = x;
	while(i/=2){
		ST[i] = ST[i*2] + ST[i*2+1];
	}
}

int minpos[maxn];
int maxpos[maxn];

void call (int i) {
	static int call_idx = 0;

	minpos[i] = 0;
	maxpos[i] = max(maxpos[i], N-query(0, current_pos[i]));

	update(current_pos[i], 0);
	current_pos[i] = N + call_idx;
	update(current_pos[i], 1);

	call_idx++;
}

void init () {
	forn(i, N){
		minpos[i] = i;
		maxpos[i] = i;
		current_pos[i] = N-1-i;
		ST[stlen+i] = 1;
	}

	for(int i = stlen; --i;)
		ST[i] = ST[i*2] + ST[i*2+1];

}

int main () {
	cin >> N >> M;

	init();

	forn(i, M){
		int caller;
		cin >> caller;
		caller -= 1;
		call(caller);
	}

	forn(i, N){
		maxpos[i] = max(maxpos[i], N - query(0, current_pos[i]));
	}

	forn(i, N){
		std::cout << (minpos[i]+1) << ' ' << (maxpos[i]) << '\n';
	}
}
