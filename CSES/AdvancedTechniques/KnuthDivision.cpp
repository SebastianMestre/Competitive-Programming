#include <iostream>
#include <algorithm>
#include <climits>

#define forr(i,s,n) for(int i{s}; i < int{n}; ++i)
#define forn(i,n) forr(i,0,n)

using namespace std;
using ll = long long;

constexpr int maxn = 5e3;
int x[maxn];
ll X[maxn+1];


ll dp[maxn+1][maxn+1];
int cut[maxn+1][maxn+1];

ll dc(int l, int r) {
	// cerr << "DC " << l << ' ' << r << "\n";
	if (r-l <= 1) {
		cut[l][r] = l;
		return 0;
	}
	if (dp[l][r] != 0) return dp[l][r];
	dc(l+1, r);
	dc(l, r-1);
	int lcut = cut[l][r-1];
	int rcut = cut[l+1][r];
	dp[l][r] = LLONG_MAX;
	cut[l][r] = -1;
	forr(k, max(lcut, l+1), min(rcut+1, r)){
	//forr(k, l+1, r){
		ll my_score = dc(l, k) + (X[r]-X[l]) + dc(k, r);
		if (my_score < dp[l][r]) {
			dp[l][r] = my_score;
			cut[l][r] = k;
		}
	}
	return dp[l][r];
}


int main () {
	int n;
	cin >> n;
	forn(i,n) cin >> x[i];
	X[0] = 0;
	forn(i,n) X[i+1] = X[i] + x[i];
	cout << dc(0, n) << '\n';
}
