#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define forn(i,n) for(int i = 0; i < int(n); ++i)
 
int maxn = 200000;
const int pot = 1 << 19;
const long long INF = 200000000000000ll;
 
long long ST[pot];
 
int qa, qb;
long long query_ (int i, int a, int b) {
	if(b <= qa or qb <= a) return -INF;
	if(qa <= a and b <= qb) return ST[i];
	int m = (a+b)/2;
	return max(query_(i*2, a, m), query_(i*2+1, m, b));
}
long long query (int a, int b) {
	qa = a;
	qb = b;
	return query_(1, 0, pot/2);
}
void update(int i, long long x){
	i += pot/2;
	ST[i] = x;
	while(i /= 2)
		ST[i] = max(ST[i*2], ST[i*2+1]);
}
 
int main () {
	int N;
	int a, b;
	cin >> N >> a >> b;
	update(0,0);
	forn(i,N){
		long long x;
		cin >> x;
		update(i+1, ST[i+pot/2]+x);
	}

	long long mval = -INF;
	forn(i, N-a+1){
		int ea = min(i+a, N+1);
		int eb = min(i+b+1, N+1);
		long long rngsum = query(ea, eb); 
		rngsum -= ST[i+pot/2];
		mval = max(mval, rngsum);
	}
	cout << mval << '\n';
}

