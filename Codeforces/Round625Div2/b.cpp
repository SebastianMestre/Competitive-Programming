#include <iostream>
#include <algorithm>
#include <map>


using namespace std;

const int maxn = 1000000;

#define forn(i,n) for(int i = 0; i< int(n); ++i)

int beauty[maxn];
int corrected[maxn];

int main () {
	int n;
	cin >> n;

	forn(i, n){
		cin >> beauty[i];
		corrected[i] = beauty[i] - i;
	}

	// equal corrected -> sum of beauty
	map<int, long long> m;
	forn(i,n){
		m[corrected[i]] += beauty[i];
	}

	long long maxv = m.begin()->second;
	for(auto& kv : m){
		maxv = max(maxv, kv.second);
	}

	cout << maxv << '\n';
}
