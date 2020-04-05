#include <iostream>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 100000;
int a[maxn];

int main () {
	int n;
	cin >> n;

	forn (i,n) {
		cin >> a[i];
	}


	if(n < 3){
		cout << "NO\n";
		return 0;
	}

	sort(a,a+n);

	forn(i,n-2){
		if(a[i] + a[i+1] > a[i+2]){
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
}


