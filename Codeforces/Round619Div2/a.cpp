#include <iostream>

#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;

int main () {
	int T;
	cin >> T;


	forn(t,T){

		string a;
		string b;
		string c;

		cin >> a >> b >> c;

		bool all_can = true;

		forn(i,a.size()){
			if(a[i] == c[i] || b[i] == c[i]) {
			} else {
				all_can = false;
				break;
			}
		}

		if(all_can){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

}
