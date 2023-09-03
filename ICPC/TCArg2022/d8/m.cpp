#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) cout<<#v" = "<<(v)<<'\n'
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

const ll MAXN = 3e4+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);



ll n, k;
ll c[MAXN];
ll d[MAXN];

bool puedo(ll l)
{
    ll count = 0;
    //db(l);
    
    forn(i, n) d[i] = c[i];
    d[n] = 0;
    
    forn(i, n)
    {
        count += d[i]/l;
        if(l <= d[i]%l + d[i+1])
        {
            d[i+1] -= l - d[i]%l;
            count ++;
        }
        
        //db(count);
        
        if(count >= k) return true;
    }
    
    assert(count < k);
    
    return count >= k;  //False
}

ll bs()
{
    ll a = 0, b = INF;
    
    while(b-a > 1)
    {
        ll m = (a+b) / 2;
        if(puedo(m)) a = m;
        else         b = m;
        
        //nn, db(m), db(puedo(m));
    }
    
    return a; //Last T
}


void solve()
{
    cin >> n >> k;
    
    forn(i, n) cin >> c[i];
    c[n] = 0;
    
    cout << bs()*k, nn;
}




int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t --) solve();
    
    return 0;
}
