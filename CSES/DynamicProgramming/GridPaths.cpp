#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); ++i)

const int MOD = 1000000007;
const int MAXN = 1010;

char board[MAXN][MAXN];
int memo[MAXN][MAXN];
int n;

int f(int i, int j) {
	if (i >= n) return 0;
	if (j >= n) return 0;
	return memo[i][j];
}

int main() {
	cin >> n;
	forn(i,n) forn(j,n) cin >> board[i][j];

	for(int i=n;i--;) for(int j=n;j--;) {
		if (board[i][j] == '*')
			memo[i][j] = 0;
		else if (i == n-1 && j == n-1)
			memo[i][j] = 1;
		else
			memo[i][j] = (f(i+1,j) + f(i,j+1)) % MOD;
	}
	cout << memo[0][0] << '\n';
}
