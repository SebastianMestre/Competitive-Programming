#include <iostream>
#include <unordered_set>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7


unordered_set<ll> squares_of_primes;

const int maxx = 1000000 + 1;
bool is_prime[maxx];

/*
bool is_tp (ll x) {
	int ans = 2;
	int y = 2;
	for(; y*y < x; ++y){
		if(x%y == 0){
			return false;
		}
	}
	if(y*y == x) ans += 1;
	return ans == 3;
}
*/

bool is_tp (ll x) {
	return squares_of_primes.count(x) == 1;
}

int main () {
	fill(is_prime, is_prime+maxx, true);
	forsn(i,2,maxx) if(is_prime[i]) for(int x = i+i; x < maxx; x += i) is_prime[x] = false;
	forsn(i,2,maxx) if(is_prime[i]) squares_of_primes.insert(ll(i)*ll(i));

	int n;
	cin >> n;

	forn(i,n){
		long long x;
		cin >> x;
		cout << (is_tp(x) ? "YES" : "NO") << '\n';
	}

}

