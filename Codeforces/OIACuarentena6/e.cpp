#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7
	using ll = long long;

struct pii {
	int coder;
	int votes;

	bool operator < (pii const& o) const {
		return votes < o.votes;
	}
};

ll pack(int a, int b) {
	return ll(a) << 32 | b;
}

pair<int, int> unpack(ll x){
	return {int(x >> 32), int(x)};
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;
	cin >> n >> p;


	unordered_map<ll, int> cantidad_acusadores_en_comun;
	unordered_map<int, int> cantidad_acusadores;
	forn(i, n){
		int x, y;
		cin >> x >> y;

		if(y < x) swap(x,y);

		cantidad_acusadores[x] += 1;
		cantidad_acusadores[y] += 1;

		cantidad_acusadores_en_comun[pack(x,y)] += 1;
	}

	ll solution = 0;
	vector<pii> v;
	forsn(i,1,n+1){
		v.push_back({i, cantidad_acusadores[i]});
	}
	sort(v.begin(), v.end());

	forn(i,n){
		auto cit = v.begin() + i;
		int x = p - cit->votes;
		auto it = lower_bound(v.begin(), v.end(), pii{-1, x});
		ll c = v.end() - it;
		if(it <= cit) c--;
		solution += c;
	}
	solution /= 2;

	for(auto const& [packed, acc] : cantidad_acusadores_en_comun){
		auto [coder1, coder2] = unpack(packed);
		int y = cantidad_acusadores[coder1] + cantidad_acusadores[coder2];
		int x = y - acc;
		if(y >= p) if(x < p) solution -= 1;
	}
	cout << solution <<'\n';
}

