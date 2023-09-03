#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forr(i,n) for(int i = n; i--;)

using namespace std;

using ll = long long;
const int maxn = 100000;
struct pt {
	double x, y;

	pt operator - (pt const& o) const {
		return {x-o.x, y-o.y};
	}

	double prod_x (pt const& o) const {
		return x * o.x - y * o.y;
	}
};

int n;
pt s[maxn];

const int total = 500;
const int splits = 16;
const int steps = total / splits;

double walk (double angle) {
	pt vec = {
		cos(angle),
		sin(angle)
	};

	double result = 0;
	for(int i = 0; i < n; ++i){
		int ni = i == n-1 ? 0 : i+1;

		pt ip = s[i];
		pt nip = s[ni];
		pt V = nip - ip;

		result += max(0.0, V.prod_x(vec));
	}

	return result;
}

double best (double lo, double hi, int depth) {
	pair<double, double> tries[splits];

	forn(i,splits){
		double percent = (double)i / (splits-1);
		double angle = lo * percent + hi * (1 - percent);
		tries[i] = {angle, walk(angle)};
	}

	int bi = 0;
	for(int i = 0; i < splits; ++i){
		if(tries[i].second < tries[bi].second){
			bi = i;
		}
	}

	if (depth == 0)
		return tries[bi].second;

	int pi = (bi-1+splits)%splits;
	int ni = (bi+1)%splits;
	if (tries[pi].second < tries[ni].second){
		return best(tries[pi].first, tries[bi].first, depth - 1);
	} else {
		return best(tries[bi].first, tries[ni].first, depth - 1);
	}
}

int main () {
	scanf("%d", &n);
	forn(i,n)
		scanf("%lf%lf", &s[i].x, &s[i].y);
	
	double result = best(0, 2 * M_PI, steps);
	printf("%.2lf\n", result);
}
