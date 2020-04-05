#include <iostream>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxk = 1000;
int c[maxk];

int potlog (long long b, int n) {
	long long acc = 1;
	while(n){
		if(n%2) {
			acc *= b;
			acc %= MOD;
		}
		b *= b;
		b %= MOD;
		n /= 2;
	}
	return acc;
}

int inv (int x) {
	return potlog(x, MOD-2);
}

int fac[1001];
int ifac[1001];

int main () {

	{
		fac[0] = 1;
		long long ans = 1;
		forsn(i,1,1000+1) {
			ans *= i;
			ans %= MOD;
			fac[i] = ans;
		}
		forn(i,1000+1){
			ifac[i] = inv(fac[i]);
		}
	}

	int k;
	cin >> k;

	forn(i,k){
		cin >> c[i];
	}

	long long len = 0;
	long long ans = 1;
	forn(i,k){
		ans *= fac[len + c[i]-1];
		ans %= MOD;
		ans *= ifac[len];
		ans %= MOD;
		ans *= ifac[c[i]-1];
		ans %= MOD;
		len += c[i];
	}

	cout << ans << '\n';
}

