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
	string s;
	cin >> s;

	int ceros = 0;
	int unos = 0;

	for(char c : s){
		if(c=='1')unos++;
		else ceros++;
	}

	cout << abs(ceros-unos) << '\n';

}

