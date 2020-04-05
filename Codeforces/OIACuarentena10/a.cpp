#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 100000;
int a[maxn];
int main () {

	int n;
	cin >> n;

	forn(i,n){
		cin >> a[i];
	}

	auto it = max_element(a,a+n);
	int maxv = *it;
	int maxi = it-a;

	map<int,int> m;
	forn(i,n){
		if(a[i] == maxv) continue;
		m[a[i]] += 1;
	}

	vector<int> s;
	for(auto [k,v] : m){
		s.push_back(k);
		m[k] -= 1;
	}

	vector<int> sb;
	for(auto [k,v] : m){
		if(v==0) continue;
		sb.push_back(k);
	}

	cout << (s.size() + 1 + sb.size()) << '\n';
	forn(i,s.size()){
		cout << s[i] << ' ';
	}
	cout << maxv << ' ';
	forrn(i,sb.size()){
		cout << sb[i] << ' ';
	}
	cout << '\n';
}

