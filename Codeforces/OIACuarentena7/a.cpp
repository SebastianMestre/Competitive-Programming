#include <iostream>
#include <cstdint>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = int(1e5) + 10;
bool isp[maxn];
int main () {
	int n;
	cin >> n;

	if (n < 3) { cout << '1' << '\n'; }
	else { cout << '2' << '\n'; }

	fill(isp, isp+maxn, true);

	forn(i,maxn){
		int c = i + 2;
		for(int x = c*2; x <= maxn; x+=c){
			isp[x] = false;
		}
	}

	forn(i,n){
		int c = i+2;
		if(isp[c]){
			cout << '1' << ' ';
		} else {
			cout << '2' << ' ';
		}
	}
	cout << '\n';

}

