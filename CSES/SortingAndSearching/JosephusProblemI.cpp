#include <iostream>
#include <set>

#define forn(i,n) for(int i = 0; i< int(n);++i)
using namespace std;



int main () {
	int n;
	cin >> n;

	set<int> s;
	forn(i, n){
		s.insert(i+1);
	}

	auto it = s.begin();
	while (!s.empty()) {
		it = next(it);
		if (it == s.end()) it = s.begin();
		cout << *it << ' ';
		it = s.erase(it);
		if (s.empty()) break;
		if (it == s.end()) it = s.begin();
	}
	cout << '\n';

}


