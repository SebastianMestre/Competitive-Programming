#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
 
#ifdef DEBUG
#define debug if(true)
#else
#define debug if(false)
#endif
 
#define forn(i,n) for(int i = 0; i < int(n); ++i)
 
using namespace std;
 
struct nodo {
    int dest;
    int idx;
    int depth;
 
    bool operator < (const nodo& o) const {
        return depth < o.depth;
    }
};
 
const int maxn = 1e5 + 50;
 
const int stlen = 1<<18;
const int stsiz = stlen*2;
 
const nodo INF = {-1,-1,int(1e9)};
 
 
int N;
int K;
 
/// *** |  | *** ///
 
 
nodo ST[stsiz];
 
void ST_init() {
    for(int i = stlen-1; i; --i){
        ST[i] = min(ST[i*2], ST[i*2+1]);
    }
}
 
nodo ST_query(int a, int b, int A = 0, int B = stlen, int idx = 1){
    if(a <= A && B <= b){
        return ST[idx];
    }else if(B <= a || b <= A){
        return INF;
    }else{
        return min(
            ST_query(a,b,A,(A+B)/2,idx*2),
            ST_query(a,b,(A+B)/2,B,idx*2+1)
        );
    }
}
 
 
/// *** |  | *** ///
 
 
bool visitado[maxn];
int padre[maxn];
nodo invord[maxn];
int stidx = 0;
 
vector<nodo> G[maxn];
 
void DFS(int x, int idx, int d) {
    visitado[x] = true;
 
    invord[x] = {stidx,idx,d};
    ST[stlen + stidx++] = {x,idx,d};
 
    for(nodo y : G[x]){
        if(!visitado[y.dest]){
            DFS(y.dest, y.idx, d+1);
 
            ST[stlen + stidx++] = {x,idx,d};
 
        }
    }
}
 
int arist[maxn];
int fools[maxn];
 
void DFS_2 (int x) {
    visitado[x] = true;
 
    for(nodo y : G[x]){
        if(!visitado[y.dest]){
            DFS_2(y.dest);
 
            fools[x] += fools[y.dest];
        }
            arist[y.idx] = fools[y.dest];
    }
 
}
 
 
int LCA(int a, int b) {
    int aidx = invord[a].dest;
    int bidx = invord[b].dest;
 
    if(aidx > bidx)
        swap(aidx, bidx);
 
    return ST_query(aidx,bidx+1).dest;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //debug freopen("fools.in", "r", stdin);
 
    cin >> N;
 
    forn(i,N-1){
        int a,b;
        cin >> a >> b;
 
        --a;--b;
 
        G[a].push_back({b,i,0});
        G[b].push_back({a,i,0});
    }
 
 
    DFS(0,0,0);
    ST_init();
 
    cin >> K;
 
    forn(i,K){
        int a,b;
        cin >> a >> b;
 
        --a;--b;
 
        fools[a]++;
        fools[b]++;
 
        fools[LCA(a,b)] -= 2;
    }
 
    fill(visitado,visitado+N+20,false);
    DFS_2(0);
 
    forn(i,N-1){
 
        cout << arist[i] << ' ';
 
    }
 
 
    return 0;
}
