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

const ll MAXN = 1e3+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);


string code(MAXN, '.'), best = "";
unordered_map<char, int> last;
vector<int> cant_dist(MAXN);


void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    
    forr(j, 1, n+1)
    {
        last.clear();
        cant_dist.assign(MAXN, 0);
        
        dforn(i, j)
        {
            char c = s[i];
            cant_dist[i] = cant_dist[i+1];
            
            if(last.find(c) == last.end()) //Primera vez que encuentro c
            {
                last[c] = i;
                cant_dist[i] ++;
            }
            
            code[i] = char('a' + cant_dist[last[c] + 1]);
            
            //db(code[i]);
        }
        
        //vecp(code.substr(0, j));
        
        best = max(best, code.substr(0, j));
    }
    
    cout << best, nn;
    
    
    
}



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
