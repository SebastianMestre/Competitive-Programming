#include<algorithm>
#include<iostream>
#include<vector>

#define forn(i,n) for(int i= 0; i < int(n); ++i)

using ll =long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x(n);
	forn(i, n)
		cin >> x[i];

	sort(x.begin(), x.end());

	ll k = 0;
	for (int xi : x) {
		if (xi > k + 1)
			break;
		k += xi;
	}

	cout << k+1 << '\n';
}
