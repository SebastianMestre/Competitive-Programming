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
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);


vector<ll> v;


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n; cin >> n;
    
    ll a = 0, b = 0;
    
    forn(i, n)
    {
        ll s; cin >> s;
        
        ll x;
        
        forn(j, s/2)
        {
            cin >> x;
            a += x;
        }
        
        if(s%2 == 1)
        {
            cin >> x;
            v.pb(x);
        }
        
        forn(j, s/2)
        {
            cin >> x;
            b += x;
        }
    }
    
    sort(v.rbegin(), v.rend());
    
    forn(i, sz(v))
    {
        if(i%2 == 0) a += v[i];
        else         b += v[i];
    }
    
    cout << a << ' ' << b, nn;
    
    return 0;
}
