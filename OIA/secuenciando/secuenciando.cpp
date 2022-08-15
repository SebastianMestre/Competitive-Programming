#include <string>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#define forr(i,s,n) for(int i = s; i < int(n); ++i)
#define forn(i,n) forr(i,0,n)

using namespace std;

int medir(string cad);

vector<int> cantidades(int N, string const& s) {
	vector<int> iota(N);
	forn(i, N) iota[i] = i+1;


	vector<int> result;
	forn(i, s.size()-1) {
		int k = distance(iota.begin(), partition_point(iota.begin(), iota.begin()+N, [&](int c){
			return medir(string(c, s[i])) == 1;
		}));
		N -= k;
		result.push_back(k);
	}
	result.push_back(N);

	return result;
}

string insert_into(string big, string const& small) {
	int i = 0;
	forn(j, small.size()) {
		while (1) {
			string big_temp = big;
			big_temp.insert(big_temp.begin()+i, small[j]);
			i += 1;
			if (medir(big_temp) == 1) {
				big = big_temp;
				break;
			}
		}
	}
	return big;
}

string dyc(vector<string> const& ws, int l, int r) {
	if (r-l == 1) return ws[l];
	int m = (l+r)/2;
	return insert_into(dyc(ws, l, m), dyc(ws, m, r));
}

string secuenciar(int N, string s)
{
	auto cs = cantidades(N, s);

	if (s == "AC") {
		return string(cs[0], 'A') + string(cs[1], 'C');
	}

	vector<string> ws;
	forn(i, s.size()) if (cs[i]) ws.emplace_back(cs[i], s[i]);

	return dyc(ws, 0, ws.size());

	auto by_size = [](string const& a, string const& b) {
		return a.size() < b.size();
	};

	while (ws.size() > 1) {
		swap(ws.back(), *min_element(ws.begin(), ws.end(), by_size));
		auto s1 = move(ws.back()); ws.pop_back();

		swap(ws.back(), *min_element(ws.begin(), ws.end(), by_size));
		auto s2 = move(ws.back()); ws.pop_back();

		ws.push_back(insert_into(s1, s2));
	}

	return ws[0];
}
