#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define fornm(i,n,m) for(int i = n; i < int(m); ++i)

string s;

bool anylen (int l) {
	if(s.size() < l) return false;

	long long mask = (1<<l)-1;
	long long buf = 0;
	vector<long long> nums;
	forn(i, l){
		buf = (buf << 1) | int(s[i] == '1');
	}
	fornm(i, l, s.size()){
		nums.push_back(buf);
		buf = mask & ((buf << 1) | int(s[i] == '1'));
	}
	nums.push_back(buf);
	sort(nums.begin(), nums.end());
	auto len = unique(nums.begin(), nums.end()) - nums.begin();
	return len != (1<<l);
}

int main () {
	int T;
	cin >> T;
	forn(t, T){
		cin >> s;

		int logn = 0;
		while(s.size() >> (++logn));

		for(int i = 1; i <= logn; ++i){
			if(anylen(i)){
				cout << i << '\n';
				break;
			}
		}
	}
}
