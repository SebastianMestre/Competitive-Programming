#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr int INF = 1<<25;

const int maxn = 100000;
const int stsize = 1<<20;
const int stlen = 1<<19;

int st1[stsize];
int st2[stsize];

int qa,qb;
int query_(int* st, int i, int a, int b){
	if(qa <= a && b <= qb) return st[i];
	if(b <= qa || qb <= a) return INF;
	int m = (a+b)/2;
	return min(query_(st,i*2,a,m), query_(st,i*2+1,m,b));
}
int query (int* st, int a, int b) {
	qa=a;qb=b;
	return query_(st,1,0,stlen);
}


int main () {

	int n,k;
	cin >> n >> k;

	fill(st1, st1+stsize, INF);
	fill(st2, st2+stsize, INF);

	forn(i,n){
		int h;
		cin >> h;
		st1[i+stlen] = h;
		st2[i+stlen] = -h;
	}

	for(int i = stlen; --i;){
		st1[i] = min(st1[i*2], st1[i*2+1]);
		st2[i] = min(st2[i*2], st2[i*2+1]);
	}

	int maxlen = 0;
	forn(i,n){

		// cerr << "@@ start=" << i << '\n';

		int a=i,b=n+1;
		while(b-a>1){
			int m = (a+b)/2;
			int minv = query(st1, i, m);
			int maxv = -query(st2, i, m);
			// cerr << "@@@ min " << minv << " max=" << maxv << '\n';
			if(maxv - minv <= k){
				a=m;
			}else{
				b=m;
			}
		}

		maxlen = max(maxlen, a-i);
	}

	set<pii> ranges;
	forn(i,n-maxlen+1){
		int minv = query(st1, i, i+maxlen);
		int maxv = -query(st2, i, i+maxlen);
		if(maxv-minv <= k){
			ranges.insert({i,i+maxlen});
		}
	}
	cout << maxlen << ' ' << ranges.size() << '\n';
	for(auto[a,b] : ranges){
		cout << a+1 << ' ' << b << '\n';
	}
}

