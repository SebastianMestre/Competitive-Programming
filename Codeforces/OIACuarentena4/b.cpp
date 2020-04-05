#include <iostream>
#include <cstdint>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 200000;
bool is_prime[maxn*3];
void sieve(){
	int n = maxn*3;
	fill(is_prime, is_prime+n, true);
	
	is_prime[0] = false;
	is_prime[1] = false;
	for(long long i = 2; i < n; ++i){
		if(is_prime[i]){
			for(long long j = i+i; j < n; ++j){
				is_prime[j] = false;
			}
		}
	}
}

int main () {
	sieve();

	int n;

	cin >> n;

	int have[3] = {};

	forn (i, n){
		int x;
		cin >> x;
		have[x] += 1;
	}

	int sum = 0;
	forn(i,n){
		if(is_prime[sum + 1] && have[1] || !have[2]){
			// place a 1
			sum += 1;
			have[1] -= 1;
			std::cout << 1 << ' ';
		} else {
			sum += 2;
			have[2] -= 1;
			std::cout << 2 << ' ';
		}
	}

	std::cout <<'\n';
}

