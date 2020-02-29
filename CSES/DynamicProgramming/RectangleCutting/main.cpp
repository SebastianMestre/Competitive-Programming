#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;
 
const int maxn = 500;
const int INF = 1 << 29;
 
static int DP[maxn+1][maxn+1];
static int GP[maxn+1][maxn+1];
 
int gcd (int a, int b) {
    if (GP[a][b]) return GP[a][b];
    if (a == 0) return GP[a][b] = b;
    return GP[a][b] = gcd(b%a, a);
}
 
int dp (int w, int h);
 
int f (int w, int h) {
    int g = gcd(w, h);
    w /= g; h /= g;
    return dp(w, h);
}
 
int dp (int w, int h) {
    if (h< w) swap(h,w);
    if (DP[w][h]) return DP[w][h];
    if (w==h) return 0;
    if (w==0) return 0;
    if (w==1) return DP[w][h] = h-1;
 
    
    int minv = INF;
    
    for(int i = 1; i <= w/2; ++i)
        minv = min(minv, 1+ f(i,h) + f(w-i,h));
    
    for(int i = 1; i <= h/2; ++i)
        minv = min(minv, 1+ f(w,i) + f(w,h-i));
    
    return DP[w][h] = minv;
}
 
int main () {
    int n,m;
    cin>>n>>m;
    
    cout << f(n,m) << '\n';
}

