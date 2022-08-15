#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i< int(n);++i)
using namespace std;

const int MAXN = 2e5;
const int P    = 18;
const int STLN = 1<<P;
const int STSZ = 1<<(P+1);

int st[STSZ];

void update(int i, int x) {
	i += STLN; st[i] = x;
	while (i /= 2) st[i] = st[i*2] + st[i*2+1];
}

void mark(int i)   { update(i, 1); }
void unmark(int i) { update(i, 0); }

int find(int x) {
	int i = 1;
	while (i < STLN) {
		i *= 2;
		if (st[i] < x) {
			x -= st[i];
			i += 1;
		}
	}
	return i-STLN+1;
}

int main () {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	forn(i,n) mark(i);

	auto sep = "";
	int i = 0;
	int count = n;
	forn(iter, n) {
		i += k; i %= count;
		int ii = find(i+1)-1;
		cout << exchange(sep, " ") << ii+1;
		unmark(ii); count -= 1;
	}
	cout << '\n';
}

