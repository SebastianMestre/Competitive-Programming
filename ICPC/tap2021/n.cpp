#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i = 0; i <int(n);++i)
#define forr(i,s,n) for(int i = s; i <int(n);++i)
#define fore(e,v) for(const auto& e : v)

using ll = long long;

struct Segtree {
	int const log2n, ln, sz;
	vector<int> data;

	Segtree(int log2n)
		:log2n{log2n}
		,ln{1 << log2n}
		,sz{1 << (log2n+1)}
		,data(1 << (log2n+1))
		{}

	// O(N)
	void init() {
		forn(i, sz) data[i] = 0;
	}

	// O(1)
	void assign_no_update(int i, int x) {
		i += ln; data[i] = x;
	}

	// O(N)
	void update_all() {
		for (int i = ln; --i;)
			data[i] = data[i*2] + data[i*2+1];
	}

	// O(logN)
	void update(int i, int x) {
		i += ln; data[i] = x;
		while (i /= 2)
			data[i] = data[i*2] + data[i*2+1];
	}

	// O(logN)
	int query(int l, int r) {
		ql = l; qr = r;
		return query_(1, 0, ln);
	}

private:
	int ql, qr;
	int query_(int i, int l, int r) {
		if (ql <= l && r <= qr) return data[i];
		if (r <= ql || qr <= l) return 0;
		int m = (l+r)/2;
		return query_(i*2,l,m) + query_(i*2+1,m,r);
	}
};

constexpr int logn = 19;
constexpr int maxn = 3e5;
constexpr int maxy = 3e5;

struct Seg {
	int jugador;
	int rango;
	int ultima;
	int tiempo;
};

struct Compe {
	int y; // anno 
	int rango; // ganadores
};

Compe contests[maxy];
Seg jugadores[maxn];
int rangocontest[maxy]; // rango del contest i

int mufa[maxn]; // mufa del jugador i

void solve() {
	Segtree st(logn);

	int y, n;
	cin >> y >> n;
	forn(i,y){
		cin >> rangocontest[i];
		contests[i] = { i, rangocontest[i] };
	}
	forn(i,n){
		int ai, pi, fi; cin >> ai >> pi >> fi; ai -= 1;
		jugadores[i] = { i, pi, ai, fi };
	}


	sort(jugadores, jugadores+n, [](auto& l, auto& r) -> bool {
		return l.rango > r.rango;
	});

	sort(contests, contests+y, [](auto& l, auto& r) -> bool {
		return l.rango > r.rango;
	});

	int i = 0, j = 0;
	for (; i < n; ++i) {
		for (; j < y && contests[j].rango >= jugadores[i].rango; ++j) {
			st.update(contests[j].y, 1);
		}
		int ret = jugadores[i].ultima;
		int inicio = ret+1;
		int fin = inicio + jugadores[i].tiempo;
		if (rangocontest[ret] >= jugadores[i].rango) {
			mufa[jugadores[i].jugador] = 0;
		} else {
			mufa[jugadores[i].jugador] = st.query(inicio, fin);
		}
	}

	forn(i,n) {
		cout << mufa[i] << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}
