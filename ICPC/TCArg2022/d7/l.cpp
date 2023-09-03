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

/** Returns the GCD of a and b. {O(log2(a+b)),=} */
ull gcd(ull a,ull b){return (b)?gcd(b,a%b):a;}

/** Returns the LCM of a and b. {O(log2(a+b)),=} */
ull lcm(ull a,ull b){return (a/gcd(a,b))*b;}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    vector<pair<ll,ll>>f(n);
    forn(i,n)cin>>f[i].fst>>f[i].snd;

    ll x=f[0].fst,y=f[0].snd;
    forr(i,1,n)x=lcm(x,f[i].fst),y=gcd(y,f[i].snd);

    cout<<x<<' '<<y,nn;
    
    return 0;
}
