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

const ll MAXN = 1e6+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);


ll n, m;

ll q[MAXN]; //Voy guardando las queries

set<ll> unused;

//Fenwick bien croto
ll tree[MAXN];


void add(int i, ll x)   //Le sumo x al elemento en posición i
{
    for(; i < MAXN; i += i & -i) tree[i] += x;
}


ll get(int b) //Devuelve la suma de los elementos en [1..b] (recordar que está indexado en 1).
{
    ll s = 0;
    
    for(int i = b; i; i -= i & -i) s += tree[i];
    
    return s;
}


void range_u(int l, int r, ll x)   //Le sumo x a los elementos en [l..r] (recordar que está indexado en 1).
{
    add(l, x);
    
    add(r+1, -x);
}


ll point_q(int i)    //Devuelve el elemento en posición i (recordar que está indexado en 1).
{
    return get(i);
}


ll copa[MAXN];
ll posicion[MAXN];


void solve()
{
    cin >> n >> m;
    
    forn(i, n) copa[i] = -1, posicion[i] = -1, unused.insert(i);
    
    int ans = 0;
    
    forn(i, m)
    {
        cin >> q[i]; q[i] --;|
        ll c; cin >> c; c --;
        
        ll pos = c - point_q(c+1);
        
        
        //db(pos);
        //db(copa[pos]);
        //db(posicion[q[i]]);
        
        if(pos < 0)
        {
            if(q[i] != q[-pos-1]) ans = -1;
        }
        else if((copa[pos] == -1 or copa[pos] == q[i]) and (posicion[q[i]] == -1 or posicion[q[i]] == pos))
        {
            range_u(0+1, c+1, 1);
            copa[pos] = q[i];
            posicion[q[i]] = pos;
            unused.erase(q[i]);
        }
        else                     ans = -1;
    }
    
    if(ans == -1)
    {
        cout << -1, nn;
        return;
    }
    
    //cout << "copa: ";
    //forn(i, n) cout << copa[i] << ' ';
    //nn;
    //cout << "posicion: ";
    //forn(i, n) cout << posicion[i] << ' ';
    //nn;
    
    forn(i, n)
    {
        if(copa[i] != -1) cout << copa[i]+1 << ' ';
        else
        {
            ll x = *unused.begin();
            unused.erase(unused.begin());
            cout << x+1 << ' ';
        }
    }
    
    nn;
}




int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
