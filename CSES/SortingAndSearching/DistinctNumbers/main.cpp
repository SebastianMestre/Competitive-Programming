#include <algorithm>
#include <cstdio>

#define forn(i,n) for(int i = 0; i< int(n); ++i)

using namespace std;

int main () {
	int N;
	scanf("%d", &N);
	int* v = new int[N];
	forn(i,N) scanf("%d", &v[i]);
	sort(v, v+N);
	auto ne = unique(v, v+N);
	printf("%d\n", int(ne - v));
	delete[] v;
}
