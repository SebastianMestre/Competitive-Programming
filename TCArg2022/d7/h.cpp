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


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin,s);
    int k,l=sz(s),idx=0;cin>>k;
    bool p=false;
    forn(i,k){
        int x;cin>>x;
        if(!p)idx=(idx+x)%l;
        else idx=(idx+(l-x))%l;
        p=!p;
    }
    if(!p){
        forn(i,l){
            int pos=(idx+i)%l;
            cout<<s[pos];
        }
    }else{
        dforn(i,l){
            int pos=(idx+i)%l;
            cout<<s[pos];
        }
    }
    nn;

    return 0;
}
