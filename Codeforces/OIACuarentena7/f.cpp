#include <iostream>
#include <cstdint>
#include <unordered_map>
#include <map>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

const int stlen = 1<<19;
const int stsize = 1<<20;

const int maxx = 1000010;
static int DP [maxx];

int D (int n) {
	return DP[n];
}

struct Monoid {
	unordered_map<int,int> counts;
	long long sum;

	Monoid () = default;
	Monoid (Monoid&&) = default;
	Monoid (Monoid const&) = default;
	Monoid& operator = (Monoid&&) = default;
	Monoid& operator = (Monoid const&) = default;
	Monoid (int x) { counts[x] = 1; sum = x; }

	Monoid operator + (Monoid const& o) const {
		Monoid result = {};
		for(auto [k,v] :   counts) result.counts[k] += v;
		for(auto [k,v] : o.counts) result.counts[k] += v;
		result.sum = result.value();
		return result;
	}

	long long value () {
		long long ans = 0;
		for(auto [k,v] : counts){ ans += ((long long)k)*v; }
		sum = ans;
		return ans;
	}
};

Monoid D (Monoid& n) {
	Monoid result = {};
	for(auto [k,v] : n.counts) {
		int d = D(k);
		result.counts[d] += v;
	}
	result.sum = result.value();
	return result;
}

Monoid ST[stsize];
int lazy[stsize];
int replaced[stsize];

int qa, qb;
void propagate (int i, int a, int b) {
	if(replaced[i] > 10) return;

	// if(lazy[i] > 0) cerr << "PROPAGATE " << i << " -> " << lazy[i] << '\n';
	forn(j, lazy[i]) {
		ST[i] = D(ST[i]);
		// cerr << "PROPAGATE LOOP " << i << '\n';
		replaced[i] += 1;
		if(replaced[i] > 10) break;
	}

	if(i < stlen){
		lazy[i*2] += lazy[i];
		lazy[i*2+1] += lazy[i];
	}

	lazy[i] = 0;
}

long long query_ (int i, int a, int b) {
	propagate(i,a,b);

	if(qa <= a && b <= qb) return ST[i].sum;
	if(b <= qa || qb <= a) return 0;

	int m = (a+b)/2;
	return query_(i*2, a, m) + query_(i*2+1, m, b);
}

void update_ (int i, int a, int b) {
	propagate(i,a,b);

	if(b <= qa || qb <= a) return;

	if(qa <= a && b <= qb) {
		// cerr << "INSIDE\n";
		lazy[i]+=1;
		propagate(i,a,b);
		return;
	}

	int m = (a+b)/2;
	update_(i*2, a, m);
	update_(i*2+1, m, b);
	ST[i] = ST[i*2] + ST[i*2+1];
}

long long query (int a, int b) {
	qa = a; qb = b;
	return query_(1, 0, stlen);
}

void update (int a, int b) {
	qa = a; qb= b;
	update_(1, 0, stlen);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	forsn(i,1, maxx){
		for(int x = i; x < maxx; x+=i){
			DP[x] += 1;
		}
	}

	int n, m;
	cin >> n >> m;

	forn(i,n){
		int x;
		cin >> x;
		ST[i+stlen] = Monoid(x);
	}

	for(int i = stlen; --i; ){
		ST[i] = ST[i*2] + ST[i*2+1];
	}

	forn(i,m){
		int t, l, r;
		cin >> t >> l >> r;
		--l;
		if(t == 1){
			update(l, r);
		} else {
			cout << query(l, r) << '\n';
		}
	}
}

