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

const ll MAXN = 7e3+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);


enum Type {L, P, G};

struct Event
{
    Type type;
    int player, pos;
    
    Event(Type _t, int _pl, int _po)
    {
        type = _t, player = _pl, pos = _po;
    }
};

Type pos[2][MAXN];
int cant[2][MAXN];
vector<int> k[2];
int sk[2];
queue<Event> q;

int n;

void print(Type t)
{
    if     (t == P) cout << "Lose ";
    else if(t == G) cout << "Win ";
    else            cout << "Loop ";
}


int submod(int a, int b) {return a < b ? a-b+n : a-b;}

void process(Event e)
{
    int i = e.player;
    
    if(e.type == P)
    {
        for(auto f : k[1-i])
        {
            int prev = submod(e.pos, f);
            
            if(pos[1-i][prev] == L)
            {
                pos[1-i][prev] = G;
                q.push(Event(G, 1-i, prev));
            }
        }
    }
    else
    {
        for(auto f : k[1-i])
        {
            int prev = submod(e.pos, f);
            
            if(pos[1-i][prev] == L)
            {
                assert(cant[1-i][prev] > 0);
                
                cant[1-i][prev] --;
                
                if(cant[1-i][prev] == 0)
                {
                    pos[1-i][prev] = P;
                    q.push(Event(P, 1-i, prev));
                }
            }
        }
    }
}



void solve()
{
    cin >> n;
    
    int aux;
    cin >> aux;
    forn(i, aux) k[0].pb(0), cin >> k[0][i];
    cin >> aux;
    forn(i, aux) k[1].pb(0), cin >> k[1][i];
    
    forn(i, 2) sk[i] = sz(k[i]);
    
    forn(i, 2) forr(j, 1, n) cant[i][j] = sk[i];
    
    pos[0][0] = P;
    pos[1][0] = P;
    
    q.push(Event(P, 0, 0));
    q.push(Event(P, 1, 0));
    
    while(not q.empty())
    {
        Event e = q.front();
        q.pop();
        process(e);
    }
    
    forr(j, 1, n) print(pos[0][j]);
    nn;
    forr(j, 1, n) print(pos[1][j]);
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
