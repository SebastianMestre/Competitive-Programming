#include <bits/stdc++.h>

using namespace std;
#define forn(i,n) for(int i = 0; i <int(n); ++i)
#define forsn(i,s,n) for(int i = s; i <int(n); ++i)

constexpr int maxn = 2e5 + 1;
int a[maxn];
int g[maxn];

int main() {
	int n;
	scanf("%d", &n);
	forn(i,n)
		scanf("%d", &a[i+1]);

	forsn(i,1,n+1){
		int j = i-1;
		while(a[i] <= a[j])
			j = g[j];
		g[i] = j;
	}

	forsn(i,1,n+1)
		printf("%s%d", (i==1?"":" "), g[i]);
	printf("\n");
}

