#include <iostream>

using namespace std;

const int maxn = 100;
const int INF = 1<<29;

#define forn(i,n) for(int i = 0; i< int(n); ++i)

int a [maxn];
int b [maxn];

int main () {
	int n;
	cin>>n;

	forn(i,n) cin >> a[i];
	forn(i,n) cin >> b[i];

	int ca = 0;
	int cb = 0;
	int ccommon = 0;
	forn(i,n){
		ca += a[i];
		cb += b[i];
		ccommon += a[i] * b[i];
	}

	if(ca == ccommon){
		cout << -1 << '\n';
		return 0;
	}

	ca -= ccommon;
	cb -= ccommon;

	int k = cb / ca + 1;

	cout << k << '\n';
}
