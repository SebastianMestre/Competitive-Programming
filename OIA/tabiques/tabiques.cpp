#include <cstdio>
#include <cassert>
#include <algorithm>
// #include <queue>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forab(i,a,b) for(int i = int(a); i < int(b); ++i)

using namespace std;

int w,h;
int t;

const int up = 1;
const int left = 2;
const int down = 4;
const int right = 8;
char vecinos[4000][4000];
int dist[4000][4000];
bool visited[4000][4000];

struct pss {short first, second;};
pss cola_buffer[16777216];

struct cola {
	int lo = 0, hi = 0;
	void push(pss const&x) {cola_buffer[hi]=x;hi=(hi+1)%16777216;}
	pss const& front()const{return cola_buffer[lo];}
	void pop() {lo=(lo+1)%16777216;}
	bool empty()const{return hi == lo;}
};
void BFS(){
    //queue<pss> Q;
	cola Q;

    Q.push({0,0});
    visited[0][0] = true;
    dist[0][0] = 0;

    while(not Q.empty()){
        pss pos = Q.front(); Q.pop();
        short x = pos.first;
		short y = pos.second;

        if(x > 0 and not (vecinos[x][y]&left) and not visited[x-1][y]){
            Q.push({x-1, y});
            visited[x-1][y] = true;
            dist[x-1][y] = dist[x][y] + 1;
        }

        if(x < w-1 and not (vecinos[x][y]&right) and not visited[x+1][y]){
            Q.push({x+1, y});
            visited[x+1][y] = true;
            dist[x+1][y] = dist[x][y] + 1;
        }

        if(y > 0 and not (vecinos[x][y]&down) and not visited[x][y-1]){
            Q.push({x, y-1});
            visited[x][y-1] = true;
            dist[x][y-1] = dist[x][y] + 1;
        }

        if(y < h-1 and not (vecinos[x][y]&up) and not visited[x][y+1]){
            Q.push({x, y+1});
            visited[x][y+1] = true;
            dist[x][y+1] = dist[x][y] + 1;
        }
    }
}

int main () {
#ifndef CLI
    FILE* ifp = fopen("tabiques.in", "r");
    FILE* ofp = fopen("tabiques.out", "w");
#else
    FILE* ifp = stdin;
    FILE* ofp = stdout;
#endif

    fscanf(ifp,"%d%d%d",&w,&h,&t);
    
    forn(i,t){
        int x0, y0, x1, y1;
        fscanf(ifp,"%d%d%d%d",&x0,&y0,&x1,&y1);

        if(x1 < x0) swap(x0, x1);
        if(y1 < y0) swap(y0, y1);
         
        if(x0 == x1) { // pared vertical
            forab(y, y0, y1){
                vecinos[x0-1][y] |= right;
                vecinos[x0][y] |= left;
            }
        } else if (y0 == y1) { // pared horizontal
            forab(x, x0, x1){
                vecinos[x][y0-1] |= up;
                vecinos[x][y0] |= down;
            }
        } else {
            assert(false);
        }
    }

    BFS();

    if(not visited[w-1][h-1]){
        fprintf(ofp,"imposible\n");
    } else {
        fprintf(ofp,"%d\n", dist[w-1][h-1]);
    }
}
