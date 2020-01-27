#include <iostream>

#define forn(i,n) for(int i = 0; i < int(n); ++i)

constexpr int maxn = 100000;
int field [2][maxn+2];

int main () {
	int N, Q;

	std::cin >> N >> Q;

	int walls = 0;
	forn(q, Q){

		int x, y;
		
		std::cin >> x >> y;

		--x; --y;
		y += 1;

		int opposite = field[1-x][y-1] + field[1-x][y] + field[1-x][y+1];
		if(field[x][y]){
			walls -= opposite;
		} else {
			walls += opposite;
		}
		field[x][y] = !field[x][y];

		// std::cerr << "field:\n";
		// forn(i, 2){
		// 	forn(j, N){
		// 		std::cerr << field[i][j+1];
		// 	}
		// 	std::cerr << '\n';
		// }

		std::cout << (walls ? "No" : "Yes") << '\n';
	}
}
