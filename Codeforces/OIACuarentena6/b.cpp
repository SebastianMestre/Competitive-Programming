#include <iostream>
#include <cstdint>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

int main () {

	int n;
	cin >> n;

	string a;
	cin >> a;

	string b;
	cin >> b;

	int swaps = 0;
	forn(i, n-1){
		if(a[i] != b[i] && a[i+1] != b[i+1] && a[i] != a[i+1]){
			swap(a[i], a[i+1]);
			++i;
			++swaps;
		}
	}

	int flips = 0;
	forn(i, n){
		if(a[i] != b[i]){
			a[i] = a[i] == '1' ? '0' : '1';
			++flips;
		}
	}

	cout << (flips + swaps) << '\n';
}

