#include <iostream>
using namespace std;

#define forr(i,s,n) for(int i = s; i < int(n); ++i)
#define forn(i,n) forr(i,0,n)

using ll = long long;
constexpr int mat_size = 6;
constexpr ll MOD = 1000000007ll;

struct vec {
	ll a[mat_size] = {};
};

struct mat {
	ll a[mat_size][mat_size] = {};
};

ll mod(ll x, ll m) { return (x%m+m)%m; }
ll m_(ll x) { return mod(x,MOD); }

mat operator* (mat const& l, mat const& r) {
	mat res = {};
	forn(i, mat_size) {
		forn(j, mat_size) {
			res.a[i][j] = 0;
			forn(k, mat_size) {
				res.a[i][j] = m_(res.a[i][j] + m_(l.a[i][k] * r.a[k][j]));
			}
		}
	}
	return res;
}

vec operator* (mat const& l, vec const& r) {
	vec res = {};
	forn(i, mat_size) {
		res.a[i] = 0;
		forn(k, mat_size) {
			res.a[i] = m_(res.a[i] + m_(l.a[i][k] * r.a[k]));
		}
	}
	return res;
}

const mat ID = {{
	{ 1, 0, 0, 0, 0, 0},
	{ 0, 1, 0, 0, 0, 0},
	{ 0, 0, 1, 0, 0, 0},
	{ 0, 0, 0, 1, 0, 0},
	{ 0, 0, 0, 0, 1, 0},
	{ 0, 0, 0, 0, 0, 1},
}};

mat pow(mat A, ll n) {
	mat T = ID;
	while (n) {
		if (n % 2 == 1) T = A * T;
		A = A * A;
		n /= 2;
	}
	return T;
}

int main() {
	ll n;
	cin >> n;

	vec v = {0,0,0,0,0,1};

	mat A = {{
		{ 0, 1, 0, 0, 0, 0},
		{ 0, 0, 1, 0, 0, 0},
		{ 0, 0, 0, 1, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
		{ 0, 0, 0, 0, 0, 1},
		{ 1, 1, 1, 1, 1, 1},
	}};

	v = pow(A, n) * v;
	cout << v.a[mat_size - 1] << '\n';
}
