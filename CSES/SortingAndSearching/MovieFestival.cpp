#include <bits/stdc++.h>

using namespace std;
#define forn(i,n) for(int i = 0; i <int(n); ++i)
#define forsn(i,s,n) for(int i = s; i <int(n); ++i)

constexpr int maxn = 2e5;

struct movie {
	int start, end;
	bool operator < (movie o) const {
		return end != o.end ? end < o.end : start < o.start;
	}
};

set<movie> s;
vector<pair<int,int>> poi;

int main () {
	int n,k;
	cin >> n >> k;

	forn(i,n){
		int a, b;
		cin >> a >> b;
		s.insert({a, b});
		poi.push_back({a,  1});
		poi.push_back({b, -1});
	}

	int t = 0;
	forn(i, poi.size()){
		t = poi.first;
	}

	cout << ans << '\n';
}
