#include <iostream>
#include <vector>
#include <string>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

constexpr int MOD = 1000000007;
using ll = long long;

using namespace std;

int main () {
	int T;
	cin >> T;

	forn(t,T){
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		// t = (y-x)/(a+b)

		int d = (y-x)/(a+b);
		int r = (y-x)%(a+b);

		if(r != 0){
			cout << -1 << '\n';
			continue;
		}

		cout << d << '\n';
	}
}
