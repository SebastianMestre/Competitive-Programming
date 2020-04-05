#include <iostream>
#include <cstdint>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

int main () {

	int n ;

	cin >> n;

	vector<int> b(n);

	forn(i, n){
		cin >> b[i];
	}

	vector<int> a(n);
	vector<int> x(n);

	a[0] = b[0];

	forsn(i, 1, n){
		x[i] = max(x[i-1], a[i-1]);
		a[i] = x[i] + b[i];
	}


	forn(i, n){
		cout << a[i] << ' ';
	}
	cout << '\n';
}

