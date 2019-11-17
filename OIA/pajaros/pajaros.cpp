#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;
	
int N;

const int maxn = 6e4;
const int maxy = 300;
const int INF = 1e7;

int altura[maxn+10];
int DP[maxn+10][maxy+10];

int costo (int x, int y) {
	if(x > N) return 0;
	if(y > maxy || y < 0) return INF;
	
	if(DP[x][y]) return DP[x][y];
	
	return DP[x][y] = min(costo(x+1, y+1), costo(x+1, y-1)) + abs(y-altura[x]);
}

/*void camino (int x, int y) {
	if(x == N) return;
	
	if(costo(x+1, y+1) < costo(x+1, y-1)) {
		cout << y+1;
		camino(x+1, y+1);
	}else{
		cout << y-1;
		camino(x+1, y-1);
	}
}*/

int main () {
	freopen("pajaros.in","r",stdin);
	freopen("pajaros.out","w",stdout);
	
	cin >> N;
	
	altura[0] = 0;
	forn(i,N)
		cin >> altura[i+1];
	
	cout << costo(0,0);
}
