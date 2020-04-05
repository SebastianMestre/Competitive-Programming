#include <iostream>
#include <string>
#include <algorithm>

#define forn(i,n) for(int i = 0; i< int(n); ++i)

using namespace std;

int main () {
	int T;
	cin >> T;
	forn(t,T){
		string s;
		cin >> s;

		auto f1 = find(s.begin(), s.end(), '1');
		auto l1 = find(s.rbegin(), s.rend(), '1').base();

		int zeroes = 0;
		
		if (f1 < l1) {
			zeroes = count(f1, l1, '0');
		}
 
		cout << zeroes << '\n';
	}
}
