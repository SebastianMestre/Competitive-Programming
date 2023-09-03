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

const ll MAXN = 1e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);



ll gcd(ll a, ll b) {return a ? gcd(b%a, a) : b;}

ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

//Devuelve {x, y} tales que a*x + b*y = gcd
pll extended_euclid(ll a, ll b)
{
    if(!b) return {1, 0};
    
    pll c = extended_euclid(b, a%b);
    ll x = c.snd;
    ll y = c.fst - (a/b)*c.snd;
    
    if(a*x + b*y < 0) x = -x, y = -y;
    
    return {x, y};
}

//Genera las soluciones de a*x + b*y = r, con r múltiplo del gcd
pair<pll, pll> diophantine(ll a, ll b, ll r)
{
    ll d = gcd(a, b);
    a /= d; b /= d; r /= d;
    auto p = extended_euclid(a, b);
    p.fst *= r; p.snd *= r;
    return {p, {-b, a}};    //Soluciones: ans.fst + k * ans.snd para todo k
}


//Mucho más rápido que el de phi.
//Si phi ya está codeada y entra en complejidad, o si pide exponente, usar esa.
//Si no, USAR ESTA.
ll inv(ll a, ll m)
{
    assert(gcd(a, m) == 1); //Comentar antes de mandar
    ll x = extended_euclid(a, m).fst;   //a*x + m*y = 1 => a*x = 1 (mod m)
    return ((x % m) + m) % m;
}



//Teorema Chino del Resto
//Requiere: gcd, lcm, inv, diophantine
#define mod(a, m) (((a)%m+m)%m)

//Dados a * x = b (mod m), devuelve (x, mod), con mod | m
pll sol(tuple<ll, ll, ll> c)
{
    ll a = get<0>(c), b = get<1>(c), m = get<2>(c), d = gcd(a, m);
    if(d == 1) return {mod(b*inv(a, m), m), m};
    else return b % d ? (pll){-1, -1} : sol(make_tuple(a/d, b/d, m/d));
}

//Dado un vector de condiciones ai * x = bi (mod mi),
//devuelve (x, mod) donde mod es el lcm de todos los módulos.
//Si el sistema no tiene solución devuelve {-1, -1}.
//Asume que lcm entra en ll (se puede cambiar todo a __int128 si no).
vector<tuple<ll, ll, ll>> cond;
pll crt()
{
    ll x1 = 0, m1 = 1, x2, m2;
    for(auto t : cond)
    {
        tie(x2, m2) = sol(t);
        if((x1 - x2) % gcd(m1, m2)) return {-1, -1};
        if(m1 == m2) continue;
        ll k = diophantine(m2, -m1, x1-x2).fst.snd, l = lcm(m1, m2);
        x1 = mod((__int128)m1*k + x1, l);
        m1 = l;
    }
    
    return sol(make_tuple(1, x1, m1));
}

//Uso:
//c.pb(make_tuple(mod(a, m), mod(b, m), m));
//pll ans = crt(c);





ll n, m, k;

pll p[MAXN];

ll best;

ll ans[MAXN];

void get_best(ll x, ll y)
{
    cond.clear();
    cond.pb(make_tuple(1, x, 2*n));
    cond.pb(make_tuple(1, y, 2*m));
    
    //db(mod(x, 2*n));
    //db(mod(y, 2*m));
    
    pll aux = crt();
    
    if(aux != pll{-1, -1})
    {
        best = min(best, aux.fst);
    }
}

void solve()
{
    cin >> n >> m >> k;
    
    forn(i, k) cin >> p[i].fst >> p[i].snd;
    
    ll r = lcm(m, n);
    
    forn(i, k)
    {
        //nn;
        ll x = p[i].fst;
        ll y = p[i].snd;
        
        best = INF;
        
        //db(x), db(y);
        
        get_best(x      , y      );
        //db(best);
        get_best(2*n - x, y      );
        //db(best);
        get_best(x      , 2*m - y);
        //db(best);
        get_best(2*n - x, 2*m - y);
        //db(best);
        
        ans[i] = best < r ? best : -1;
        
        //db(ans[i]);
    }
    
    forn(i, k) cout << ans[i], nn;
}





int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
