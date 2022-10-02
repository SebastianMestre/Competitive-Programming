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

    int n,q,total=0,next=0,ans=0;cin>>n>>q;

    vector<bool>unread(q,true);
    vector<stack<int>>notifs(n);

    forn(_,q){
        int t,x;cin>>t>>x;

        if(t==1){
            notifs[x-1].push(total);
            ++total;
            ++ans;
        }else if(t==2){
            while(!notifs[x-1].empty()){
                int curr=notifs[x-1].top();
                notifs[x-1].pop();
                if(unread[curr]){
                    unread[curr]=false;
                    --ans;
                }
            }
        }else{
            forr(i,next,x){
                if(unread[i]){
                    unread[i]=false;
                    --ans;
                }
            }
            next=max(next,x);
        }      

        cout<<ans,nn;
    }
    
    return 0;
}
