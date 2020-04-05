#include <iostream>
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
using namespace std;

// POST CONTEST

const int maxn = 2000;
struct pt {
	int x, y;
};
pt ps[maxn];
int main () {
	int n;
	cin >> n;
	forn(i,n){ cin >> ps[i].x >> ps[i].y; }

	long long solution = 0;
	forn(i,n){
		pt pi = ps[i];
		forsn(j,i+1,n){
			pt pj = ps[j];
			forsn(k,j+1,n){
				pt pk = ps[k];

				pt dj = {pj.x-pi.x, pj.y-pi.y};
				pt dk = {pk.x-pi.x, pk.y-pi.y};

				int det = dj.x*dk.y - dj.y*dk.x;
				
				if(det != 0){
					solution+=1;
				}
			}
		}
	}
	cout << solution <<'\n';
}
