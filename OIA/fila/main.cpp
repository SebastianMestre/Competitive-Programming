#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;

using ll = long long;

struct Fecha
{
    int dia, mes, anno;
};

ll flatten(Fecha f) {
	return f.dia+f.mes*32+f.anno*13ll*32;
}

int fila(vector<Fecha> orden, vector<int>& enojados){
	using cell = pair<ll,int>;

	auto by_age = [](cell a, cell b){
		return a.first != b.first ? a.first > b.first : a.second > b.second;
	};

	auto by_pos = [](cell a, cell b){
		return a.second < b.second;
	};

	vector<cell> v;

	forn(i,orden.size())
		v.push_back({flatten(orden[i]), i});

	sort(v.begin(), v.end(), by_age);

	vector<pair<int,int>> res;

	// cerr << "\n\n====\n";
	cell fwd = {1<<29, 1<<29};
	int max_enojo = 0;
	forn(i,v.size()){
		int enojo = max(0, v[i].second - fwd.second);
		max_enojo = max(max_enojo, enojo);
		if(enojo){
			res.push_back({-enojo, v[i].second});
		}
		//cerr << (v[i].second+1) << " tiene enojo de " << enojo <<'\n';
		fwd = min(fwd, v[i], by_pos);
	}

	sort(res.begin(), res.end());
	for(auto x : res){
		enojados.push_back(x.second+1);
	}

	return max_enojo;
}
