#include <iostream>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

bool es_primo (long long n) {
	if(n == 1) return false;
	for(long long x = 2; x*x <= n; ++x)
		if(n % x == 0)
			return false;
	return true;
}

int main () {
	long long n;
	cin >> n;

	if(es_primo(n) || n == 1){
		cout << n << '\n';
		return 0;
	}

	long long m = n;
	int d_prim = 0;
	long long p = 1;
	for(long long x = 2; x*x <= n; ++x){
		if(n % x == 0){
			if(es_primo(x)) {
				d_prim++;
				p = x;
			}
			long long y = n / x;
			if(x != y && es_primo(y)) {
				d_prim++;
				p = y;
			}
		}
	}

	if(d_prim != 1){
		cout << 1 << '\n';
	} else {
		cout << p << '\n';
	}

}
