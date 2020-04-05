#include <iostream>
#include <cstdint>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

bool pred (long long n, long long m) {
	long long on = n;
	long long veat_tot = 0;
	while(n>0){
		long long veat = min(n, m);
		n -= veat;

		long long peat = n / 10;
		n -= peat;

		veat_tot += veat;
	}
	return veat_tot >= (on+1)/2;
}

int main () {

	long long n;
	cin >> n;

	long long a = 0;
	long long b = n;

	while(b-a > 1){
		long long m = (a+b)/2;
		if(pred(n,m)){
			b = m;
		} else {
			a = m;
		}
	}

	cout << b << '\n';
}

