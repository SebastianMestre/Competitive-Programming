#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i = 0; i <int(n);++i)
#define forr(i,s,n) for(int i = s; i <int(n);++i)
#define fore(e,v) for(const auto& e : v)

using ll = long long;

constexpr int maxn = 1e5;
constexpr int maxk = 1e5;

vector<int> values_by_color[maxk];
vector<int> indices_by_color[maxk];

int a[maxn];

void solve() {
	int n ,k;
	cin >> n >> k;

	forn(i,n) {
		int x, c;
		cin >> x >> c;

		c -= 1;

		indices_by_color[c].push_back(i);
		values_by_color[c].push_back(x);
	}

	forn(c,maxk){
		sort(values_by_color[c].begin(), values_by_color[c].end());
		forn(i, values_by_color[c].size()) {
			a[indices_by_color[c][i]] = values_by_color[c][i];
		}
	}

	if (is_sorted(a, a+n)){
		cout << "Y\n";
	} else {
		cout << "N\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}
