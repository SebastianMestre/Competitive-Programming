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
const ll MOD = 1e9+9;
const ld EPS = 1e-9;
const ld PI = acosl(-1);


ll addmod(ll a, ll b) {ll r=a+b; if(r>=MOD) r-=MOD; return r;}
ll submod(ll a, ll b) {ll r=a-b; if(r<0) r+=MOD; return r;}

ll expmod(ll b, ll e, ll m = MOD)
{
    if(!e) return 1;
    ll q = expmod(b, e/2, m); q = q*q%m;
    return e&1 ? b*q%m : q;
}


void fact(ll n, map<ll, int> &F)
{
    for(ll p = 2; p*p <= n; p ++) while(n%p == 0) F[p] ++, n /= p;
    if(n > 1) F[n] ++;
}


void solve()
{
    ll k, d, m; cin >> k >> d >> m;
    
    if(m%d != 0)
    {
        cout << 0, nn;
        return;
    }
    
    map<ll, int> F, G;
    fact(d, F);
    fact(m, G);
    
    ll ans = 1;
    
    for(auto x : G)
    {
        ll p = x.fst;
        int b = x.snd;
        int a = F[p];
        
        if(a != b)
        {
            ll aux = submod(submod(expmod(b-a+1, k), expmod(b-a, k)), expmod(b-a, k)) % MOD;
            aux = addmod(aux, expmod(b-a-1, k));
            ans = ans * aux % MOD;
        }
    }
    
    cout << ans, nn;
}



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
