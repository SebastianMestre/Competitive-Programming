#include <iostream>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

const int maxn = 500;

int walks[maxn];
int miss[maxn];

int main () {
	int n, k;

	cin >> n >> k;

	forn(i,n){
		cin >> walks[i];
	}

	forn(i, n-1){
		miss[i] = max(0, k - (walks[i] + walks[i+1]));
	}

	int extra = 0;

	forn(i, n-1){
		extra += miss[i];
		walks[i+1] += miss[i];
		miss[i+1] = max(0, miss[i+1] - miss[i]);
	}

	cout << extra << '\n';
	forn(i,n){
		cout << walks[i] << ' ';
	}
	cout << '\n';
}
