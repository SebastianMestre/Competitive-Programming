#include <iostream>
#include <string>
#include <cstdint>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

int main () {
	string s;

	cin >> s;

	string hello = "hello!";
	int j = 0;
	for(char c : s){
		if(c == hello[j]){
			j += 1;
		}
	}

	cout << (hello[j] == '!' ? "YES" : "NO") << '\n';

}

