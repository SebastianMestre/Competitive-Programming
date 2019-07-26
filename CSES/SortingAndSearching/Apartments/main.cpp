#include <algorithm>
#include <cstdio>

#define forn(i,n) for(int i = 0; i< int(n); ++i)

using namespace std;

int main () {
	int N;
	int M;
	int k;

	scanf("%d %d %d", &N, &M, &k);

	int* a = new int[N];
	int* b = new int[M];

	forn(i, N) scanf("%d", &a[i]);
	forn(i, M) scanf("%d", &b[i]);

	sort(a, a+N);
	sort(b, b+M);

	int c = 0;
	int j = 0;
	int i = 0;
	while(i < N && j < M){
		if(b[j] > a[i] + k) {
			i++;
			continue;
		} else if(b[j] < a[i] - k) {
			j++;
			continue;
		} else {
			//printf("** %d(%d) -> %d(%d) **\n", i, a[i], j, b[j]);
			i++;
			j++;
			c++;
			continue;
		}
	}

	printf("%d\n", c);

	delete[] a;
	delete[] b;
}
