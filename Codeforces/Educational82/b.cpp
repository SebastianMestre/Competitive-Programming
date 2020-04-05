#include <iostream>
#include <string>
#include <algorithm>

#define forn(i,n) for(int i = 0; i< int(n); ++i)

using namespace std;

int main () {
	int T;
	cin >> T;
	forn(t,T){
		long long g, b, n;
		cin >> n >> g >> b;

		if(n == 1){
			cout << 1 << '\n';
		} else if(g > b){
			cout << n << '\n';
		} else {

			long long good_road_need = (n+1)/2; // partes buenas necesarias

			long long cycles_need = (good_road_need-1) / g; // cantidad de temporadas malas

			long long days = cycles_need * b + good_road_need; // temporadas malas * dias malos por temporada + dias buenos

			cout << max(n, days) << '\n';
		}
	}
}
