#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

struct person {
	int i;
	int h;
	bool operator < (person const& o) const {
		return h < o.h;
	}
};

const int maxn = 200000;

vector<int> G[maxn];
person w[maxn];
int a[maxn];

void dfs (int v, int h) {
	w[v].h = h;
	for(int u : G[v])
		dfs(u, h+1);
}

ll score_even[maxn];
ll score_odd[maxn];

// effective score odd
ll eff_so(int i) { return max(score_odd[i], a[i] + score_even[i]); }
// effective score even
ll eff_se(int i) { return score_even[i]; }

int main () {

	int n;
	cin >> n;

	forn(i,n){
		int p;
		cin >> p >> a[i];
		--p;
		if(p>=0)
		G[p].push_back(i);
		w[i] = {i};
	}

	dfs(0,0);

	sort(w, w+n);
	reverse(w, w+n);

	forn(i,n){
		person p = w[i];

		if(G[p.i].size() == 0){
			score_odd[p.i] = -INF;
			score_even[p.i] = 0;
			continue;
		}

		vector<int> good_even;
		for(int j : G[p.i]) good_even.push_back(eff_se(j)-eff_so(j));
		sort(good_even.begin(), good_even.end());

		{
			ll best_s[2] = {-INF, -INF};

			int parity = 0; // 0 par , 1 impar
			ll ss = 0; // score

			// assume all even at first
			for(int j : G[p.i]) ss += eff_se(j);

			best_s[parity] = max(best_s[parity], ss);

			for(int k = 0; k < good_even.size(); k += 1){
				ss -= good_even[k];
				parity = !parity;
				best_s[parity] = max(best_s[parity], ss);
			}

			 score_even[p.i] = best_s[0];
			 score_odd[p.i] = best_s[1];
		}
	}

	cout << eff_so(0) << '\n';
}

