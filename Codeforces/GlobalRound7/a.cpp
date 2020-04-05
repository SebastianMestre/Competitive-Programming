#include <iostream>
#include <cstdint>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 32Mi --- 33M
constexpr int MOD = 1000000007; // 1e9+7

int main () {

	int T;

	cin >> T;

	forn (t, T){
		int n;
		cin >> n;

		if(1 < n) {
			forn(i, n-1){
				cout << '5';
			}
			cout << '4' << '\n';
		} else {
			cout << "-1\n";
		}

	}
}

