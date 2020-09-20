#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

struct val { int l, r, t, i; };

const int maxn = 4000;
int n;
val v[maxn];

// reach[i] es el indice del primer rango que no toca el rango i
int reach[maxn];
int dp[maxn][maxn+1][2];

int fn(int i, int j, int t){
	if(i == n) return 0;
	if(dp[i][j][t] != -1) return dp[i][j][t];

	// por defecto, no tomo el actual
	int op1 = fn(i+1, j, t);
	dp[i][j][t] = op1;

	// si el indice no esta tapado
	// o esta tapado por uno del mismo equipo
	// veo si conviene tomar el actual
	if(i >= j || t == v[i].t) {
		int op2 = fn(i+1, max(j, reach[i]), v[i].t) + 1;
		dp[i][j][t] = max(dp[i][j][t], op2); 
	}

	return dp[i][j][t];
}

vector<val> took;

void store(int i, int j, int t){
	while(1){
		if(i == n) return;

		// no tomo
		int op1 = fn(i+1, j, t);
		int nj = j;
		int nt = t;

		// si puedo, tomo
		if(i >= j || t == v[i].t){
			int op2 = fn(i+1, max(j, reach[i]), v[i].t) + 1;
			if(op2 > op1){
				took.push_back(v[i]);
				nj = max(j, reach[i]);
				nt = v[i].t;
			}
		}

		i = i+1;
		j = nj;
		t = nt;
	}
}

int main () {
#ifndef LOCAL
	freopen("mercachifle.in", "r", stdin);
	freopen("mercachifle.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(dp, -1, sizeof(dp));

	int a;
	cin >> a;
	forn(i, a){
		cin >> v[i].l >> v[i].r;
		v[i].i = i;
		v[i].t = 0;
	}

	int b;
	cin >> b;
	forn(ii, b){
		int i = ii + a;
		cin >> v[i].l >> v[i].r;
		v[i].i = ii;
		v[i].t = 1;
	}

	n = a + b;
	sort(v, v+n, [](val lhs, val rhs){
		return lhs.l != rhs.l
			? lhs.l < rhs.l
			: lhs.r < rhs.r;
		});

	forn(i,n){
		int x = v[i].r;
		int hi = n, lo = i+1;
		while(hi != lo){
			int md = (hi+lo)/2;
			if(x < v[md].l) hi = md;
			else            lo = md+1;
		}
		reach[i] = hi;
		assert(reach[i] > i);
	}

	int r = fn(0,0,0);
	cout << r << '\n';

	took.reserve(r);
	store(0,0,0);

	{
		auto it = partition(took.begin(), took.end(), [](val x){
				return x.t == 0;
			});

		for(auto i = took.begin(); i != it; ++i){
			cout << 1+i->i;
			if(i+1 != it) cout << ' ';
		}
		cout << '\n';

		for(auto i = it; i != took.end(); ++i){
			cout << 1+i->i;
			if(i+1 != took.end()) cout << ' ';
		}
		cout << '\n';

	}
}
