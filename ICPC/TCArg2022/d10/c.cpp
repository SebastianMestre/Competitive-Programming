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

const ll MAXN = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acosl(-1);





ll expmod(ll b, ll e)
{
    if(!e) return 1;
    ll q = expmod(b, e/2); q = q*q%MOD;
    return e&1 ? b*q%MOD : q;
}

ll inv(ll a)
{
    return expmod(a, MOD-2);
}



int n;
ll itres;

unordered_map<ll, unordered_map<int, ll>> tabla;

ll& memo(int i, int j, int k) {
    ll idx = ll(i) * MAXN + j;
    return tabla[idx][k];
}


ll dp(int z, int y, int x)
{
    if((z >= 1 and               x >= 2) or
       (z >= 1 and z-1 + 3*y + 4*x >= n) or
       (z >= 1 and z-1 + 2*x       >= n) or
       (                 2*y + 2*x >= n))
    {
        return 0;
    }
    
    ll &m = memo(z,y,x);
    
    if(m != 0) return m;
    
    return m = (1 + itres*(((dp(z+1, y, x) + dp(z, y+1, x)) % MOD + dp(z, y, x+1)) % MOD)) % MOD;
}



void solve()
{
    cin >> n;
    
    itres = inv(3);
    
    cout << dp(0, 0, 0) % MOD, nn;
}



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
