#include <bits/stdc++.h>

using namespace std;

#define forr(i,s,n) for(int i =s; i < int(n); ++i)
#define forn(i,n) forr(i,0,n)

using ll = long long;

using Sc = double;
struct pt { Sc x, y; };

double len(pt const& p) { return hypot(p.x, p.y); }
pt operator+ (pt const& a, pt const& b) { return {a.x + b.x, a.y + b.y}; } // suma
pt operator* (Sc const& x, pt const& p) { return {x * p.x, x * p.y}; } // producto por un escalar


void report(int idx, char c) {
	cerr << "(" << idx << ") READ '" << c << "' (" << int(c) << ")\n";
}

istream& read(int idx, char& c) {
	auto& res = cin >> c;
	// report(idx, c);
	return res;
}

int main() {
	double sr2 = sqrt(2.0) / 2.0;

	pt dirs[8] = {
		{+1.0,  0.0},
		{+sr2, +sr2},
		{ 0.0, +1.0},
		{-sr2, +sr2},
		{-1.0,  0.0},
		{-sr2, -sr2},
		{ 0.0, -1.0},
		{+sr2, -sr2},
	};

	int idx = 0;
	char c;
	while (read(0, c)) {
		idx ++;

		if (c == 'E') {
			cin >> c >> c;
			break;
		}

		assert(isdigit(c));

		pt pos = {0.0, 0.0};

		while (1) {
			ll x = 0;
			do {
				x *= 10;
				x += c - '0';
				read(1, c);
			} while (isdigit(c));
			// cerr << "BREAK\n";


			int d;
			switch(c) {
				break; case 'E': d = 0; read(2, c);
				break; case 'W': d = 4; read(3, c);
				break; case 'N': {
					d = 2;
					read(4, c);
					if (c == 'E') { d -= 1; read(5, c); }
					if (c == 'W') { d += 1; read(6, c); }
				}
				break; case 'S': {
					d = 6;
					read(7, c);
					if (c == 'E') { d += 1; read(8, c); }
					if (c == 'W') { d -= 1; read(9, c); }
				}
				break; default: assert(0);
			}

			// cerr << "STEPS: " << x << " -- DIR: " << d << "\n";
			pos = pos + x * dirs[d];

			if (c == ',') {
				read(10, c);
				continue;
			} else if (c == '.') {
				break;
			}
		}

		printf("Map #%d\n", idx);
		printf("The treasure is located at (%.3f,%.3f).\n", pos.x, pos.y);
		printf("The distance to the treasure is %.3f.\n\n", len(pos));

	}

}
