#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forr(i,n) for(int i = n; i--;)

using namespace std;

using ll = long long;

const int maxn = 100;
const ll MOD = 1000000007;

ll choose[maxn][maxn];

ll W[maxn];
ll PS[maxn];
ll A;
ll B;

bool good(ll s){
	return A <= s && s <= B;
}

ll f(int i, int k, ll s){
	// cerr << "f(" << i << " " << k << " " << s << ")\n";
	if(k == 0) return good(s) ? 1 : 0;
	if(i < 0) return 0;
	if(s > B) return 0;
	if(i+1 < k) return 0;
	if(s + W[i] > B) return f(i-1, k, s);
	if(s + W[i] + W[i] < A) return 0;
	if(s + W[i] < A) return f(i-1, k-1, s+W[i]);
	if(good(s) && good(s+W[i]))
		return choose[i][k] + f(i-1, k-1, s+W[i]);
	return f(i-1, k, s) + f(i-1, k-1, s+W[i]);
}

int main () {
	forn(i,maxn){
		forn(j,maxn){
			if(j > i) break;
			else if(j == 0 || j == i) choose[i][j] = 1;
			else choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
		}
	}

	int n, k;
	cin >> n >> k;
	forn(i,n){
		cin >> W[i];
	}
	cin >> A >> B;
	sort(W,W+n);
	// cerr << "@";
	// forn(i,n)
		// cerr << ' '<< W[i];
	// cerr << '\n';
	cout << f(n-1, k, 0) << '\n';
}
