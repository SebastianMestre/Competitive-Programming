#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i< int(n); ++i)
#define forsn(i,s,n) for(int i = s; i< int(n); ++i)
#define forr(i,n) for(int i = n; i--;)
constexpr int maxn = int(1e3) + 2;

using ll = long long;

int storage1[maxn];
int storage2[maxn];
int storage3[maxn];

char a[maxn][maxn];

int*const hg = storage1 + 1;
int*const fl = storage2 + 1;
int*const fr = storage3 + 1;

int n,m;

int main () {
		char c;
	scanf("%d%d",&n,&m);
	scanf("%c", &c);
	forn(i,n) {
		forn(j,m)
			scanf("%c",&a[i][j]);
		scanf("%c", &c);
	}

	fl[-1] = -1;
	fr[ n] =  n;

	hg[-1] = -1;
	hg[ n] = -1;

	auto compute = [](int i, int j, int* arr){
		while(hg[i] <= hg[j])
			j = arr[j];
		arr[i] = j;
	};

	ll best = 0;
	forn(j, m) {
		forn(i, n) hg[i] = a[i][j] == '*' ? 0 : hg[i] + 1;

		forn(i, n) compute(i, i-1, fl);
		forr(i, n) compute(i, i+1, fr);

		forn(i,n){
			int l = fl[i];
			int r = fr[i];
			int w = (r-l) - 1;
			best = max(best, (ll)w * hg[i]);
		}
	}

	cout << best << '\n';
}
