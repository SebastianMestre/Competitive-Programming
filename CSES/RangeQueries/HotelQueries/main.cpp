#include <iostream>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
using namespace std;

constexpr int maxn = 200000;
constexpr int pot = 1 << 19;

int ST[pot];
int N;

void update(int i, int x){
	i+= pot/2;
	ST[i] -= x;
	while(i/=2){
		ST[i] = max(ST[i*2], ST[i*2+1]);
	}
}

int qa, qb;
int query_impl (int i, int a, int b) {
	if(b <= qa or qb <= a) return -10000;
	if(qa <= a and b <= qb) return ST[i];
	int m = (a+b)/2;
	return max(query_impl(i*2, a, m), query_impl(i*2+1, m, b));
}
int query(int a, int b){
	qa = a; qb = b;
	return query_impl(1, 0, pot/2);
}

int get (int x) {
	int a = 0;
	int b = N;

	while(a!=b){
		int m = a+(b-a)/2;
		int v = query(0, m+1);
		if(v < x){
			a = m+1;
		} else {
			b = m;
		}
	}

	return a;
}

int main () {
	int M;
	cin >> N >> M;
	forn(i,N){
		int x;
		cin >> x;
		update(i,-x);
	}

	forn(i,M){
		int x;
		cin >> x;
		int j = get(x);
		update(j, x);
		if(j == N)
			cout << 0;
		else
			cout << j+1;
		cout << ' ';
	}
}
