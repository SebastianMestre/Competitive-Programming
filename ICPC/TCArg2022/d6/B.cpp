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

/** Given str returns l such that l[i] is the size of the longest proper prefix
 * that is also a suffix of the first i elements of str. {O(m),=} */
template<class T>vector<int>lpps(T& str){
  int m=sz(str);
  vector<int>l(m);
  for(int i=1,len=0;i<m;)
    if(str[i]==str[len])l[i++]=++len;
    else if(len)len=l[len-1];
    else l[i++]=0;
  return l;
}

/** Returns the start of the ocurrences of str in txt using Knuth-Morris-Pratt.
 * {O(n+m),=} */
template<class T>vector<int>kmp(T& txt,T& str){
  int n=sz(txt),m=sz(str);
  vector<int>pos,l=lpps(str);
  for(int i=0,j=0;i<n;) {
    if(str[j]==txt[i])++j,++i;
    if(j==m)pos.pb(i-j),j=l[j-1];
    else if(i<n&&str[j]!=txt[i]) j=(j)?l[j-1]:(++i,j);
  }
  return pos;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;
    int m=sz(s),n;
    cin>>n;
    vector<int>v(m,-1);
    forn(i,n){
        string curr;
        cin>>curr;
        vector<int>pos=kmp(s,curr);
        for(int x:pos){
            if(v[x]==-1)v[x]=sz(curr)-1;
            else v[x]=min(v[x],sz(curr)-1);
        }
    }

    int pos=-1,len=-1,curr=0;
    v.pb(0);
    forn(i,m+1){
        ++curr;
        if(v[i]!=-1){
            int rem=v[i],last=i;
            while(rem){
                --rem,++last,++curr;
                if(v[last]!=-1){
                    rem=min(rem,v[last]);
                }
            }
            --curr;
            if(curr>len){
                len=curr;
                pos=last-curr;
                assert(len>=0);
                assert(pos>=0);
                assert(pos<=m-len);
            }
            curr=0;
        }
    }

    assert(len>=0);
    assert(pos>=0);

    cout<<len<<' '<<pos;
    nn;

    return 0;
}