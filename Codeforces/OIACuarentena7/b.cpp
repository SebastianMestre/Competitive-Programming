#include <iostream>
#include <cstdint>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 100000;
int guy[maxn];

int out[maxn];

int main () {
	int n;
	cin >> n;

	forn(i,n){
		int name;
		cin >> name;
		--name;
		guy[name] = i;
	}

	forn(i,n){
		int name;
		cin >> name;
		--name;

		out[i] = guy[name];
	}

	int runmin = n;
	int ilegal = 0;
	forn(j,n){
		int i = n-j-1;


		if(runmin < out[i]) ilegal++;

		runmin = min(runmin, out[i]);

	}

	cout << ilegal << '\n';
}



