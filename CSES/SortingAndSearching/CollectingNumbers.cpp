#include <iostream>
#include <vector>

#define forn(i,n) for(int i= 0; i < int(n); ++i)

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int m;
	cin >> n >> m;

	vector<int> x(n);
	vector<int> p(n);
	forn(i,n){
		cin >> x[i];
		x[i] -= 1;
		p[x[i]] = i;
	}

	int k = 1;
	forn(i,n-1)
		k += p[i+1] < p[i];
	cout << k << '\n';
}
