#include <iostream>
#include <unordered_map>
#include <cstdint>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

int main () {
	int n;

	cin >> n;

	std::unordered_map<int, int> m1;
	forn (i, n){
		int h;
		cin >> h;
		m1[h] += 1;
	}

	std::unordered_map<int, int> m2;
	forn (i, n-1){
		int h;
		cin >> h;

		m1[h] -= 1;
		m2[h] += 1;
	}

	forn (i, n-2){
		int h;
		cin >> h;

		m2[h] -= 1;
	}

	for(auto [k,v] : m1){
		if(v == 1) {
			std::cout << k << '\n';
			break;
		}
	}

	for(auto [k,v] : m2){
		if(v == 1) {
			std::cout << k << '\n';
			break;
		}
	}
}

