#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i< int(n); ++i)
#define forsn(i,s,n) for(int i = s; i< int(n); ++i)
#define forr(i,n) for(int i = n; i--;)
constexpr int maxn = int(2e5) + 2;

using ll = long long;

int storage1[maxn];
int storage2[maxn];
int storage3[maxn];

int*const a  = storage1 + 1;
int*const fl = storage2 + 1;
int*const fr = storage3 + 1;

int n;

int main () {
	scanf("%d",&n);
	forn(i,n) scanf("%d",&a[i]);

	a[-1] = 0;
	a[ n] = 0;

	fl[-1] = -1;
	fr[ n] =  n;

	auto compute = [](int i, int j, int* arr){
		while(a[i] <= a[j])
			j = arr[j];
		arr[i] = j;
	};

	forn(i,n) compute(i, i-1, fl);
	forr(i,n) compute(i, i+1, fr);

	ll best = 0;
	forn(i,n){
		int l = fl[i];
		int r = fr[i];
		int w = (r-l) - 1;
		best = max(best, (ll)w * a[i]);
	}

	cout << best << '\n';
}
