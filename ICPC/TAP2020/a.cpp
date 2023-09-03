#include <iostream>
#include <vector>
#include <queue>
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forr(i,n) for(int i = n; i--;)

using namespace std;

using real = long double;
const int MAXN = 1<<20;

int N, A, B, K;

real S[MAXN];
real Accum[MAXN];

int main () {

    //freopen("entrada.txt", "r", stdin);

    scanf("%d%d%d", &N, &A, &B);
    K = B - A + 1;

    /// ASSUME A > 0

    // no need to draw cards
    S[0] = 0;
    // one card always suffices
    forsn(i, 1, A+1){
        S[i] = 1;
        Accum[i] = i;
    }
    // we may need more than one
    forsn(i, A+1, B+1){
        S[i] = 1 + (Accum[i-1]/K - Accum[A-1]/K);
        Accum[i] = Accum[i-1] + S[i];
    }
    // we need more than one for certain
    forsn(i, B+1, N+1){
        S[i] = 1 + (Accum[i-A]/K - Accum[i-B-1]/K);
        Accum[i] = Accum[i-1] + S[i];
    }
    printf("%Lf\n", (long double)S[N]);


    return 0;
}
