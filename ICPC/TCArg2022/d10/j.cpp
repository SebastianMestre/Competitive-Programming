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

class Graph {
  public:
    int n;
    vector<vector<int>>adj;
    Graph(int _n);
    void add_edge(int u,int v);
    vector<int>bfs(int o=0);
};

Graph::Graph(int _n):n(_n),adj(_n){}

void Graph::add_edge(int u,int v){
  adj[u].pb(v),adj[v].pb(u);
}

vector<int>Graph::bfs(int o){
  vector<int>d(n,INT_MAX);
  d[o]=0;
  queue<int>q;
  q.push(o);
  while(!q.empty()){
    int x=q.front(); q.pop();
    for(const int&y:adj[x])if(d[y]==INT_MAX)d[y]=d[x]+1,q.push(y);
  }
  return d;
}

string to_string_with_zeros(int u){
    string s="0000";
    const int total=4;
    forn(i,total){
        s[total-i-1]=char('0'+(u%10));
        u/=10;
    }
    return s;
}

int to_int_with_zeros(const string&s){
    int u=0,tens=1;
    const int total=4;
    forn(i,total){
        u+=tens*(s[total-i-1]-'0');
        tens*=10;
    }
    return u;
}

void single(string&s,int idx,int offset){
    s[idx]=char(s[idx]+offset);
    if(s[idx]>'9')s[idx]='0';
    else if(s[idx]<'0')s[idx]='9';
}

string move(const string&s,int start,int len,int offset){
    string ans=s;
    forr(i,start,start+len){
        single(ans,i,offset);
    }
    return ans;
}

vector<int>get_vs(int u){
    string s=to_string_with_zeros(u);
    vector<int>ans;
    ans.reserve(30);
    const int total=4;
    forn(i,total){
        int len=i+1;
        forn(j,total-i){
            string up=move(s,j,len,1);
            string down=move(s,j,len,-1);
            ans.pb(to_int_with_zeros(up));
            ans.pb(to_int_with_zeros(down));
        }
    }
    return ans;
}

void convert(string&a,string&b){
    const int total=4;
    forn(i,total)while(a[i]!='0')single(a,i,-1),single(b,i,-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int nodes=10000;
    Graph g(nodes);
    dforn(u,nodes){
        vector<int>vs=get_vs(u);
        for(const int&v:vs)g.add_edge(u,v);
    }

    vector<int>d=g.bfs();

    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        convert(a,b);
        cout<<d[to_int_with_zeros(b)],nn;
    }
    
    return 0;
}
