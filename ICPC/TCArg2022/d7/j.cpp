#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define vecp(v) cerr<<#v<<" = "; for(auto ee:v)cerr<<ee<<' '; cerr<<'\n'
#define nn cout<<'\n'
#define sz(v) (int(v.size()))
#define all(v) v.begin(), v.end()
#define pb push_back
#define pp pop_back
#define fst first
#define snd second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll MAXN = 1e3+100;
const ll MAXK = 2*MAXN;
const ll INF = 1e18+100;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

ll addmod(ll a, ll b) {ll r=a+b; if(r>=MOD) r-=MOD; return r;}

ll dp[4][MAXN][MAXK];

void solve()
{
    int n, k; cin >> n >> k;
    
    //dp[0][i][j]: cant de formas de dejar j cc en un tablero de 2*(i+1),}
    //terminando con BB
    //dp[1][i][j]: cant de formas de dejar j cc en un tablero de 2*(i+1),}
    //terminando con BN
    //dp[2][i][j]: cant de formas de dejar j cc en un tablero de 2*(i+1),}
    //terminando con NB
    //dp[3][i][j]: cant de formas de dejar j cc en un tablero de 2*(i+1),}
    //terminando con NN
    
    dp[0][0][1] = 1;
    dp[1][0][2] = 1;
    dp[2][0][2] = 1;
    dp[3][0][1] = 1;
    
    forr(i, 1, n)
    {
        forr(j, 1, k+1)
        {
            dp[0][i][j] = addmod(addmod(addmod(dp[0][i-1][j], dp[1][i-1][j]), dp[2][i-1][j]), dp[3][i-1][j-1]);
            dp[1][i][j] = addmod(addmod(dp[0][i-1][j-1], dp[1][i-1][j]), dp[3][i-1][j-1]);
            dp[2][i][j] = addmod(addmod(dp[0][i-1][j-1], dp[2][i-1][j]), dp[3][i-1][j-1]);
            dp[3][i][j] = addmod(addmod(addmod(dp[0][i-1][j-1], dp[1][i-1][j]), dp[2][i-1][j]), dp[3][i-1][j]);
            
            if(j >= 2)
            {
                dp[1][i][j] = addmod(dp[1][i][j], dp[2][i-1][j-2]);
                dp[2][i][j] = addmod(dp[2][i][j], dp[1][i-1][j-2]);
            }
        }
    }
    
    cout << addmod(addmod(addmod(dp[0][n-1][k], dp[1][n-1][k]), dp[2][n-1][k]), dp[3][n-1][k]), nn;
}



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
