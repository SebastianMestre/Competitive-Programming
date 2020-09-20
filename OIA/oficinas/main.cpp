#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

const int maxn = 250;

struct val{int x, k;};
val v[maxn];

int ps[maxn+1];
int dp[maxn+1][maxn+1];
int pv[maxn+1][maxn+1]; // pivot


void print(int l, int r){
	if(l == r) return;
	int piv = pv[l][r];
	cout << '(';
	print(l, piv);
	cout << v[piv].x;
	print(piv+1, r);
	cout << ')';
}

int main () {
	freopen("oficinas.in", "r", stdin);
	freopen("oficinas.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;

	forn(i,n){
		cin >> v[i].x >> v[i].k;
	}

	sort(v, v+n, [](val a, val b){ return a.x < b.x; });

	ps[0] = 0;
	forn(i,n) ps[i+1] = ps[i] + v[i].k;

	forn(l,n+1)
		dp[l][l] = 0;

	forsn(L, 1, n+1){
		forn(l, n-L+1){
			int r = l + L;

			int res = 1 << 30;
			int piv = -1;
			forsn(m, l, r){
				int my_res = dp[l][m] + dp[m+1][r] + (ps[r] - ps[l]);

				if(my_res < res){
					res = my_res;
					piv = m;
				}
			}

			pv[l][r] = piv;
			dp[l][r] = res;
		}
	}


	cout << dp[0][n] << '\n';
	print(0, n);
	cout << '\n';
}
