#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define fore(e,v) for(const auto&e:(v))

#define db(n) cerr<<#n" = "<<(n)<<endl

#define pb push_back
#define uset unordered_set
#define fst first
#define snd second

typedef long long ll;

using Sc = ll; // scalar
struct pt {
	Sc x, y;

};

Sc det(pt const& a, pt const& b) { return a.x*b.y - a.y*b.x; }
Sc dot(pt const& a, pt const& b) { return a.x*b.x + a.y*b.y; }
pt operator+ (pt const& a, pt const& b) { return {a.x + b.x, a.y + b.y}; }
pt operator- (pt const& a, pt const& b) { return {a.x - b.x, a.y - b.y}; }
bool ccw(pt const& o, pt const& a, pt const& b) { return det(a - o, b - o) > 0; }
bool cw(pt const& o, pt const& a, pt const& b) { return det(a - o, b - o) < 0; }

template<typename T> T& operator << (T& o, pt const& p) { return o << "(" << p.x << ", " << p.y << ")"; }

vector<pt> chull(vector<pt> v) {
	auto it = min_element(v.begin(), v.end(), [](pt const& a, pt const& b) {
		return (a.x != b.x) ? a.x < b.x : a.y < b.y;
	});
	swap(v[0], *it);
	sort(v.begin()+1, v.end(), [&](pt const& a, pt const& b) {
		return cw(v[0], b, a);
	});
	int j = 2;
	forr(i, 2, v.size()) {
		while (j >= 2 && !ccw(v[j-2], v[j-1], v[i])) j--;
		v[j++] = v[i];
	}
	v.resize(j);
	return v;
}

bool solve() {
	int n; if(!(cin >> n)) return false;;

	vector<pt> ps(n); forn(i,n) cin >> ps[i].x >> ps[i].y;

	// cerr << "BEGIN POINTS\n"; for (auto const& p : ps) cerr << p << "\n"; cerr << "END POINTS\n"; 

	vector<pt> ch = chull(move(ps));

	// cerr << "BEGIN CHULL\n"; for (auto const& p : ch) cerr << p << "\n"; cerr << "END CHULL\n";

	int m = ch.size();

	ll best = 0;
	forn (i, n) {
		// db(i);
		int k = i+1;
		forr (j, i+2, i+m) {
			ll area = det(ch[k%m] - ch[i%m], ch[j%m] - ch[i%m]);
			while (1) {
				if (k+1 >= j) break;
				ll next_area = det(ch[(k+1)%m] - ch[i%m], ch[j%m] - ch[i%m]);
				if (next_area < area) break;
				area = next_area;
				k += 1;
			}
			best = max(best, area);
		}
	}

	printf("%.1lf\n", best / 2.0);

	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


	while (solve());
}
