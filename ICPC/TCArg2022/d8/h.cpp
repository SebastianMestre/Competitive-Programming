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

ll sqr(ll x){
    return x*x;
}

ll dist(const pair<ll,ll>&u,const pair<ll,ll>&v){
    return sqr(u.fst-v.fst)+sqr(u.snd-v.snd);
}

bool aligned(const pair<ll,ll>&a,const pair<ll,ll>&b,const pair<ll,ll>&c){
    if(a.fst==b.fst&&a.fst==c.fst&&!a.fst)return true;
    if(a.snd==b.snd&&a.snd==c.snd&&!a.snd)return true;
    ll x1=a.fst-b.fst;
    ll x2=a.fst-c.fst;
    ll y1=a.snd-b.snd;
    ll y2=a.snd-c.snd;
    return x1*y2==x2*y1;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    pair<ll,ll>a,b,c;
    cin>>a.fst>>a.snd;
    cin>>b.fst>>b.snd;
    cin>>c.fst>>c.snd;

    if(dist(a,b)!=dist(b,c)||aligned(a,b,c))cout<<"No";
    else cout<<"Yes";
    nn;

    return 0;
}
