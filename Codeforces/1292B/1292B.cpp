#include <iostream>
#include <utility>

#define forn(i,n) for(int i = 0; i < int(n);++i)

using ll = long long int;
using pll = std::pair<ll, ll>;
constexpr ll bignumber = 10000000000000000; // 10**16

ll x0, y0, ax, ay, bx, by, xs, ys, t;

pll point_DP[64];
pll next_point(pll p){
	p.first *= ax;
	p.second *= ay;
	p.first += bx;
	p.second += by;
	return p;
}
pll prev_point(pll p){
	p.second -= by;
	p.first -= bx;
	p.second /= ay;
	p.first /= ax;
	return p;
}
pll point(int i) {
	return point_DP[i];
}

ll ll_abs (ll x) { return x < 0 ? -x : x; }
ll dist (pll a, pll b) { return ll_abs(a.first - b.first) + ll_abs(b.second - a.second); }

bool can_reach (pll a, pll b, ll tr) {
	return dist(a, b) <= tr;
}
bool can_reach_next (pll p, ll tr) {
	return !(
		(p.first >= bignumber) || (p.second >= bignumber) || (p.first + p.second > bignumber)
		|| (t < bx + by) || (t-bx-by < p.first*ax) || (t-bx-by < p.second*ay) || (t-bx-by < p.first*ax + p.second*ay)
	);
}
bool can_reach_prev (pll p, ll tr) {
	return can_reach(prev_point(p), p, tr);
}

bool is_in_bounds (pll p) {
	return p.first <= bignumber*2 && p.second <= bignumber*2;
}
int last = -1;
void init () {
	int i = 0;
	pll p = point_DP[i] = {x0, y0};
	while(is_in_bounds(p)){
		i++;
		p = point_DP[i] = next_point(p);
	}
	last = i;
}

int main () {
	std::cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	init();

	int best = 0;
	pll s = {xs, ys};
	for(int i = 0; i <= last; ++i) {
		if(can_reach(s, point(i), t)){
			{ // going upwards

				pll pp = s;
				pll p = point(i);

				ll tr = t - dist(p, pp);

				int count = 1;
				int j = i;
				while (1) {
					const int nj = j+1;

					if (nj > last)
						break;

					pll np = point(nj);

					if (dist(p, np) > tr)
						break;

					count++;

					tr -= dist(p, np);
					pp = p;
					p = np;

					j = nj;
				}

				best = best < count ? count : best;
			}
			{ // going downwards
				pll pp = s;
				pll p = point(i);

				ll tr = t - dist(p, pp);

				int count = 1;
				int j = i;
				while (1) {
					const int nj = j-1;

					if (nj < 0)
						break;

					pll np = point(nj);

					if (dist(p, np) > tr)
						break;

					count++;

					tr -= dist(p, np);
					pp = p;
					p = np;

					j = nj;
				}

				best = best < count ? count : best;
			}
		}
	}

	std::cout << best << '\n';
}
