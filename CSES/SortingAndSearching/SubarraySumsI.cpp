#include <bits/stdc++.h>

using namespace std;
#define forn(i,n) for(int i = 0; i <int(n); ++i)
#define forsn(i,s,n) for(int i = s; i <int(n); ++i)

constexpr int maxn = 2e5;

using ll = long long;

ll s[maxn+1];

int main () {
	int n, x;
	cin >> n >> x;
	forn(i,n){
		cin >> s[i+1];
		s[i+1] += s[i];
	}

	unordered_map<ll, int> m;
	ll ans = 0;
	constexpr ll K = 0xdeadfacecafebabell;
	forsn(j, 0, n+1){
		auto it = m.find((s[j]-x)^K);
		if(it != m.end()) ans += it->second;
		m[s[j]^K] += 1;
	}
	cout << ans << '\n';
}
