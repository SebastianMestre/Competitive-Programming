#include <iostream>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); ++i)

constexpr int maxn = 50000; // 50k
constexpr int pot = 1<<17; // 128ki ~= 131k

struct range {
	int lo, hi;
	long long val;

	bool operator < (range const& o) const {
		return val < o.val;
	}
};

bool canJoin (range const& lhs, range const& rhs) {
	return lhs.hi == rhs.lo;
}

range join (range const& lhs, range const& rhs) {
	range result;
	result.lo = lhs.lo;
	result.hi = rhs.hi;
	result.val = lhs.val + rhs.val;
	return result;
}

struct piece {
	range left;
	range right;
	range best;
	range full;
};

piece join (piece const& lhs, piece const& rhs) {
	piece result;
	result.full = join(lhs.full, rhs.full);

	result.left = max(lhs.left, join(lhs.full, rhs.left));

	result.right = max(rhs.right, join(lhs.right, rhs.full));

	result.best = max(max(max(lhs.best, rhs.best), max(result.left, result.right)), max(result.full, join(lhs.right, rhs.left)));

	return result;
}

piece flatpiece (int a, int b, int x) {
	return {
		{a, a, x},
		{b, b, x},
		{a, b, x},
		{a, b, x},
	};
}
piece nullpiece (int a, int b) {
	return flatpiece(a,b,-100000);
}

piece ST[pot];

int qa, qb;
piece query (int i, int va, int vb) {
	if(qa <= va and vb <= qb) return ST[i];
	if(vb <= qa or qb <= va) return nullpiece(va, vb);
	int m = (va+vb)/2;
	return join(
		query(i*2, va, m),
		query(i*2+1, m, vb)
	);
}
int do_query (int a, int b) {
	qa = a;
	qb = b;
	piece res = query(1, 0, pot/2);
	return res.best.val;
}

void init () {
	for(int i = 0; i < pot/2; ++i){
		ST[i+pot/2] = nullpiece(i, i+1);
	}
	for(int i = pot/2; --i;){
		ST[i] = join(ST[i*2], ST[i*2+1]);
	}
}

void update(int i, int x) {
	i += pot/2;
	ST[i] = flatpiece(i, i+1, x);
	while(i/=2){
		ST[i] = join(ST[i*2], ST[i*2+1]);
	}
} 

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	int N;
	cin >> N;
	forn(i,N){
		int x;
		cin >> x;
		update(i,x);
	}
	int M;
	cin >> M;
	forn(i,M){
		int qt, x, y;
		cin >> qt >> x >> y;
		if(qt == 0){ // modify
			update(x-1, y);
		} else { // print
			// 1[x,y] -> 0[x,y)
			cout << do_query(x-1, y) << '\n';
		}
	}
}
