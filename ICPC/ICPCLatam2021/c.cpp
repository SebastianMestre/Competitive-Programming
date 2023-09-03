#include <iostream>
#include <algorithm>
#include <cassert>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forr(i,s,n) for(int i = s; i < int(n); ++i)
#define rforn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

int N, S, G[200020], P[200020];
ll Ans;

ll calculate(){
    forn(i, N)
        G[i+N] = G[i];

    P[0] = G[0];
    forn(i, 2*N) P[i+1] = P[i] + G[i+1];

	int start = ((min_element(P, P+2*N)-P) + 1) % N;
	ll cost = 0;
	int balance = 0;
    forn(i, N){
        int idx = start + i;
        cost += balance;   // record how many cups I have in my hand
        balance += G[idx]; // take/leave cups on table
    }
    return cost;
}

int main () {

	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	forn(i, N){
        scanf("%d", G+i);
        S += G[i];
	}
	forn(i, 2*N) G[i] -= S/N;

    Ans = calculate();
    reverse(G, G+N);
    Ans = min(Ans, calculate());

    printf("%lld\n", Ans);

	return 0;
}

