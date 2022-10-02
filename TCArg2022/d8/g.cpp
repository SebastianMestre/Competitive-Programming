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
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);


ll dos[MAXN];
int c[MAXN];

ll factorial[2*MAXN], invfact[2*MAXN], inv[2*MAXN];

void init()
{
    inv[1] = 1;
    
    factorial[0] = 1;
    factorial[1] = 1;
    
    invfact[0] = 1;
    invfact[1] = 1;
    
    forr(i, 2, 2*MAXN)
    {
        inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;  //Inversos modulares hasta 2*MAXN
        
        factorial[i] = factorial[i - 1] * i % MOD;  //Factoriales hasta 2*MAXN
        
        invfact[i] = invfact[i-1] * inv[i] % MOD;   //Inversos de los factoriales hasta 2*MAXN
    }
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    dos[0] = 1;
    dos[1] = 1;
    
    forr(i, 2, MAXN) dos[i] = 2*dos[i-1] % MOD;
    
    init();
    
    int n, m; cin >> n >> m;
    
    int a = 0, b = 0;
    
    ll ans = 1;
    
    forn(i, m) cin >> c[i];
    
    sort(c, c+m);
    
    forn(i, m)
    {
        b = c[i];
        
        if(i)
        {
            ans = ans * dos[b-a-1] % MOD;
        }
        
        if(b-a-1 != 0) ans = ans * invfact[b-a-1] % MOD;
        
        a = b;
    }
    
    b = n+1;
    if(b-a-1 != 0) ans = ans * invfact[b-a-1] % MOD;
    
    ans = ans * factorial[n-m] % MOD;
    
    cout << ans, nn;
    
    
    return 0;
}
