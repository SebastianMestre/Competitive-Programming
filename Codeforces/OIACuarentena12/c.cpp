#include <iostream>
#include <cmath>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

int r;


const int maxn = 1000;
int x[maxn];
double y[maxn];

double height_from (int x1, int x2, double y2) {
	int dx = x1-x2;
	if(abs(dx) >= 2*r){
		return abs(dx) == 2*r ? double(y2) : r;
	} else {
		return y2 + sqrt(4*r*r - (dx*dx));
	}
}

int main () {
	int n;
	cin >> n >> r;
	forn(i,n){
		cin >> x[i];
		double yi = r;
		forn(j, i){
			yi = max(yi, height_from(x[i], x[j], y[j]));
		}
		y[i] = yi;
		printf("%.9f ", yi);
	}
	putchar('\n');
}

