
using ll = long long;
struct vec {
	ll x, y;

	int qu
}

vec operator-(vec lhs, vec rhs) {
	return {lhs.x-rhs.x, lhs.y-rhs.y};
}

bool operator<(vec lhs, vec rhs) {
	if (lhs.x != rhs.x)
		return lhs.x < rhs.x;
	else
		return lhs.y < rhs.y;
}

bool lt_polar(vec lhs, vec rhs) {
	int ql = lhs.cuadrant();
	int qr = rhs.cuadrant();
	if (ql != qr) { return ql < qr; }
	ll p = lhs ^ rhs;
	if (p != 0) {
		return 0 < p;
	}
	return lhs.n2() < rhs.n2();
}
