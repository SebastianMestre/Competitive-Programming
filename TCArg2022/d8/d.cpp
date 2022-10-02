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

typedef double tipo; //Se puede cambiar a ll si me dan todo en enteros.

struct pto      //¡Los vectores (geométricos) también son puntos!
{
    tipo x=0, y=0;
    pto operator+(const pto& o) const { return {x + o.x, y + o.y}; }
    pto operator-(const pto& o) const { return {x - o.x, y - o.y}; }
    tipo operator*(const pto& o) const { return x * o.x + y * o.y; } //Producto escalar
    tipo operator^(const pto& o) const { return x * o.y - y * o.x; } //Producto vectorial (no conmutativo, me cambia el signo)
    bool left(pto q, pto r){return ((q - *this) ^ (r - *this)) > 0;}    //p.left(q, r) = T si p está a la izquierda de la recta qr dirigida (no colineal).
    bool operator<(const pto& a) const{return x < a.x - EPS || (abs(x - a.x) < EPS && y < a.y - EPS);}
};

pto operator*(tipo k, const pto& p) { return {k * p.x, k * p.y}; } //Producto entre escalar y vector (EN ESE ORDEN)

struct Bowl {
    tipo h=1,r=1,R=2;
};

struct Segment {
    pto u,v;
};

struct PlacedBowl {
    Segment left,mid;
};

tipo intersecar(const Segment&s,const Segment&q){
    tipo p1=s.u,d1=s.v,p2=q.u,d2=p2.v;
    tipo alpha = tipo((p2 - p1) ^ d2) / tipo(d1 ^ d2);
    pto p=p1+alpha*d1;
    if(p.x < q.u.x) return q.u.y;
	if(p.x > q.v.x) return q.v.y;
	return p.y;
}

tipo solve(const vector<int>&perm,const vector<Bowl>&bowls){
    vector<PlacedBowl>placed;
    tipo height=0;
    for(int idx:perm){
        const Bowl&curr=bowls[idx];
        //Segment base;
        //base.u.x=-curr.r/2;
        //base.u.y=height;
        Segment vertical={{-curr.r/2},{0,1}};
        for (const PlacedBowl&p:placed) {
            // Me fijo si la base choca algun borde
            tipo dh=intersecar(vertical,p.left);

        }
    }
    return height;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<Bowl>bowls(n);
        forn(i,n)cin>>bowls[i].h>>bowls[i].r>>bowls[i].R;
        vector<int>perm(n);
        forn(i,n)perm[i]=i;
        tipo ans=INF;
        do{
            ans=min(ans,solve(perm,bowls));
        }while(next_permutation(all(perm)));

        cout<<floor(ans);
        nn;
    }
    
    return 0;
}
