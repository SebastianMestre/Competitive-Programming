#include <bits/stdc++.h>

using namespace std;

#define forr(i,s,n) for(int i=s;i<int(n);++i)
#define forn(i,n) forr(i,0,n)

using ll = long long;

using Sc = ll;
struct pt { Sc x, y; };

bool operator<(pt const& a, pt const& b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }
bool operator==(pt const& a, pt const& b) { return a.x == b.x && a.y == b.y; }

int main() {
	int t; cin >> t;

	while (t--) {

		int n; cin >> n;

		vector<pt> pts(n);

		forn(i,n) cin >> pts[i].x >> pts[i].y;

		vector<pt> qts = pts;

		sort(pts.begin(), pts.end());

		ll least_x = pts[0].x;
		ll great_x = pts[n-1].x;

		forn(i,n) pts[i].x = pts[i].x - least_x;
		forn(i,n) qts[i].x = great_x - qts[i].x;

		sort(qts.begin(), qts.end());

		bool sym = equal(pts.begin(), pts.end(), qts.begin());

		// forn(i,n/2) cerr << "(" << pts[i].x << " " << pts[i].y << ") =?= (" << qts[i].x << " " << qts[i].y << ")\n";

		cout << (sym ? "YES" : "NO") << "\n";
	}
}
