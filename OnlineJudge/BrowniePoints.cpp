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
	while (1) {
		int n; cin >> n; if (n == 0) break;

		vector<pt> pts(n);
		forn(i,n) cin >> pts[i].x >> pts[i].y;

		pt c = pts[n/2];

		int score1 = 0;
		int score2 = 0;
		forn(i,n){
			ll k = (c.x - pts[i].x) * (c.y - pts[i].y);
			score1 += (k > 0);
			score2 += (k < 0);
		}
		cout << score1 << " " << score2 << "\n";
	}
}
