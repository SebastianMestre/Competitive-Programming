#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define fornn(i,s,n) for(int i = s; i < int(n); ++i)
#define forr(i,n) for(int i = n; i--;)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<30; // >1e9
constexpr int MOD = 1000000007; // 1e9+7

constexpr int maxn = 1e5;
constexpr int stln = 1<<17;
constexpr int stsz = stln << 1;

namespace Sum {
int st[stsz];
int ql, qr;

int qy_(int i, int l, int r) {
	if (r <= ql || qr <= l) return 0;
	if (ql <= l && r <= qr) return st[i];
	int m = (l+r)/2;
	return qy_(i*2, l, m) + qy_(i*2+1, m, r);
}

void up_(int i, int x) {
	st[i] += x;
	while (i /= 2) st[i] = st[i*2] + st[i*2+1];
}

int query_impl(int l, int r) {
	ql = l; qr = r;
	return qy_(1, 0, stln);
}

void update_impl(int i, int x) {
	return up_(i+stln, x);
}


int query(int i) {
	return query_impl(0, i+1);
}

void update(int i, int j) {
	update_impl(i, 1);
	update_impl(j, -1);
}

}

namespace RMQ{
pair<int,int> st[stsz];
int ql, qr;
using T = pair<int,int>;

T qy_(int i, int l, int r) {
	if (r <= ql || qr <= l) return {-INF, -1};
	if (ql <= l && r <= qr) return st[i];
	int m = (l+r)/2;
	return max(qy_(i*2, l, m) ,qy_(i*2+1, m, r));
}

void up_(int i, T x) {
	st[i] = x;
	while (i /= 2) st[i] = max(st[i*2], st[i*2+1]);
}

T query(int l, int r) {
	ql = l; qr = r;
	return qy_(1, 0, stln);
}

void assign(int i, T x) {
	return up_(i+stln, x);
}

}

vector<int> h;
vector<pair<int,int>> v;

#define INDEX second

void dyc(int l, int m, int r) {
	if (r-l < 2)
		return;

	Sum::update(l, m);
	Sum::update(m+1, r);

	if (l < m) {
		auto lm = RMQ::query(l, m);
		int midpoint = (m + lm.INDEX + 1) / 2; // div2, round up
		dyc(l, lm.INDEX, midpoint);
	}

	if (m+1 < r) {
		auto rm = RMQ::query(m+1, r);
		int midpoint = (m + rm.INDEX)/2;
		dyc(midpoint+1, rm.INDEX, r);
	}
}

int main () {
	int n;
	cin >> n;

	h.resize(n);
	v.resize(n);

	forn (i,n) {
		cin >> h[i];
		RMQ::assign(i, {h[i], i});
	}

	auto q = RMQ::query(0, n);
	dyc(0, q.INDEX, n);

	auto sep = "";
	forn(i,n) {
		cout << sep << Sum::query(i);
		sep = " ";
	}
	cout << '\n';
}
