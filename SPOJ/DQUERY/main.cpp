#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdio>
#include <cmath>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forab(i,a,n) for(int i = a; i < int(n); ++i)

using namespace std;

constexpr int maxn = 30000;

int N;
int sqn;
int numbers[maxn];

struct range {
	int a, b;
	int i;
	bool operator < (range const & o) const {
		return (a/sqn) != (o.a/sqn) ? (a/sqn) < (o.a/sqn) : b < o.b;
	}
};

int LO = 0;
int HI = 0;
array<int, 1000001> freq;
int ans = 0;

int query (int lo, int hi) {
	while(LO < lo) {
		freq[numbers[LO]]--;
		if(freq[numbers[LO]] == 0) ans--;
		LO++;
	}
	while(HI < hi) {
		if(freq[numbers[HI]] == 0) ans++;
		freq[numbers[HI]]++;
		HI++;
	}

	while(HI > hi) {
		HI--;
		freq[numbers[HI]]--;
		if(freq[numbers[HI]] == 0) ans--;
	}
	while(LO > lo) {
		LO--;
		if(freq[numbers[LO]] == 0) ans++;
		freq[numbers[LO]]++;
	}

	return ans;
}

int main () {
	int Q;

	scanf("%d", &N);
	sqn = int(sqrt(N));

	forn(i, N)
		scanf("%d", &numbers[i]);
	
	scanf("%d", &Q);

	vector<range> ranges;
	forn(i, Q){
		int a, b;
		scanf("%d %d", &a, &b);
		ranges.push_back({a, b+1, i});
	}

	sort(ranges.begin(), ranges.end());
	vector<range> out;
	for(auto r : ranges){
		int q = query(r.a-1, r.b-1);
		out.push_back({r.i, q, r.i});
	}

        sort(out.begin(), out.end(),
             [](auto const &a, auto const &b) { return a.i < b.i; });
        for(auto r : out){
		printf("%d\n", r.b);
	}
}
