#include<iostream>
#include<algorithm>
 
#define forn(i,n) for(int i=0;i<int(n);++i)
using namespace std;
 
const int maxn = 101;
const int maxk = 1000001;
 
int a[maxn];
int dp[maxn][maxk];
 
int main () {
    int n,x;
    
    cin >> n >> x;
 
    forn(i,n){
        cin >> a[i];
    }
 
    forn(i,n)forn(s,x+1)dp[i][s]=maxk+maxk;
    forn(i,n)dp[i][0]=0;
 
    forn(i,n)forn(s,x+1){
        if(i>0)
            dp[i][s]=min(dp[i][s], dp[i-1][s]);
        if(s>=a[i])
            dp[i][s]=min(dp[i][s], 1+dp[i][s-a[i]]);
    }
 
    if(dp[n-1][x] >= maxk+maxk)
        cout << "-1\n";
    else
        cout << dp[n-1][x] << '\n';
}
