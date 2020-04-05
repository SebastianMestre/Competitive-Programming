#include <iostream>
#include <vector>
#include <string>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

constexpr int MOD = 1000000007;
using ll = long long;

using namespace std;

struct data {
	int t, l, h;
	bool empty;
};

data intersect (data const& a, data const& b){
	int l = max(a.l, b.l);
	int h = min(a.h, b.h);

	return {a.t, l, h};
}

int main () {
	int Q;
	cin >> Q;

	forn(q,Q){
		int n, m;

		cin >> n >> m;

		vector<data> d;
		forn(i,n){
			int t, l, h;
			cin >> t >> l >> h;
			d.push_back({t,l,h});
		}

		{
			int j = 0;
			for(int i = 0; i < n; ++i){
				if(d[i].t == d[j].t){
					d[j] = intersect(d[i], d[j]);
				} else {
					++j;
					d[j] = d[i];
				}
			}
			d.resize(j+1);
			n = j+1;
		}

		bool can = true;
		int L = m;
		int H = m;
		int T = 0;
		forn(i,n){

		   	int l = d[i].l;
		   	int h = d[i].h;

			if(l > h){
				can = false;
				break;
			}

			int t = d[i].t;

			int dt = t - T;

			int hpossible = H + dt;
			int lpossible = L - dt;

			if(hpossible < l || lpossible > h){
				can = false;
				break;
			}

			H = min(hpossible, h);
			L = max(lpossible, l);
			T = t;
		}

		if(can){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
