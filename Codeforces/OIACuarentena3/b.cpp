#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define forn(i,n) for(int i = 0;  i < int(n); ++i)

int main () {
	map<int,int> chicos;
	int n, m;
	cin >> n;
	forn(i,n){
		int d;
		cin >> d;
		chicos[d] += 1;
	}
	vector<int> chicas;
	cin >> m;
	forn(i,m){
		int d;
		cin >> d;
		chicas.push_back(d);
	}
	sort(chicas.begin(), chicas.end());

	int matches = 0;
	forn(i, chicas.size()){
		// cerr << "Current girl " << chicas[i] << '\n';
		auto it = chicos.begin();
attempt:
		it = chicos.lower_bound(chicas[i]-1);
		if(it == chicos.end()){
			// cerr << "no good enough boys " << '\n';
			break;
		}
		if(it->second == 0){
			// cerr << "erasing boy group " << it->first << '\n';
			chicos.erase(it);
			goto attempt;
		}
		if(abs(it->first - chicas[i]) > 1){
			// cerr << "no bad enough boys " << '\n';
			continue;
		}

		// cerr << "* " << chicas[i] << " -- " << it->first << '\n';

		matches++;
		it->second -= 1;
	}

	cout << matches << '\n';
}
