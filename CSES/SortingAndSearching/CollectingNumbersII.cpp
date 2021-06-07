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


	forn(t, m) {
		int a, b;
		cin >> a >> b;
		a -= 1; b -= 1;

		int q = x[a];
		int r = x[b];

		if (q < r) {
			swap(q, r);
			swap(a, b);
		}

		             if(q < n-1) k -= p[q+1] < p[q];
		             if(q > 0)   k -= p[q] < p[q-1];

		if(r+1 != q) if(r < n-1) k -= p[r+1] < p[r];
		             if(r > 0)   k -= p[r] < p[r-1];

		swap(x[a], x[b]);
		swap(p[q], p[r]);

		             if(q < n-1) k += p[q+1] < p[q];
		             if(q > 0)   k += p[q] < p[q-1];

		if(r+1 != q) if(r < n-1) k += p[r+1] < p[r];
		             if(r > 0)   k += p[r] < p[r-1];

		cout << k << '\n';
	}
}
