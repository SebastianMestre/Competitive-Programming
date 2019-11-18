#include <cstdio>
#include <algorithm>
#include <utility>
#include <cassert>
#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;

constexpr int maxn = 30000;
constexpr int maxq = 200000;
constexpr int len = 1 << 15;

struct Query {
	int lo, hi;
	int k, i;
	int result;
};

struct Value {
	int k, i;
};

Value arr[maxn];
Query queries[maxq];
int ft[len];

void update (int i) {
	i++;
	for(; i < len; i+=i&-i)
		ft[i]++;
}

int query (int i) {
	i++;
	int v = 0;
	for(; i>0; i-=i&-i)
		v+=ft[i];
	return v;
}
int do_query (int a, int b) {
	return (b-a) - (query(b-1) - query(a-1));
}

int main () {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	int N;
	int Q;

	// cin >> N;
	scanf("%d", &N);
	assert(N <= maxn);

	forn(i,N){
		// cin >> arr[i].k;
		scanf("%d", &arr[i].k);
		arr[i].i = i;
	}

	sort(arr, arr+N, [](Value const& a, Value const& b){ return a.k < b.k; });

	// cin >> Q;
	scanf("%d", &Q);
	assert(Q <= maxq);

	forn(i,Q){
		// cin >> queries[i].lo
			// >> queries[i].hi
			// >> queries[i].k;
		scanf("%d", &queries[i].lo);
		scanf("%d", &queries[i].hi);
		scanf("%d", &queries[i].k);
		queries[i].lo--;
		queries[i].i = i;
	}

	sort(queries, queries+Q, [](Query const& a, Query const& b){ return a.k < b.k; });

	int j = 0;
	forn(i,Q){
		while(arr[j].k <= queries[i].k)
			update(arr[j++].i);

		queries[i].result = do_query(queries[i].lo, queries[i].hi);
	}

	/*
	// Unsort + print in linear time
	forn(i,Q){
		while(i != queries[i].i)
			swap(queries[i], queries[queries[i].i]);
		// cout << queries[i].result << '\n';
		printf("%d\n", queries[i].result);
	}
	*/

	sort(queries, queries+Q, [](Query const& a, Query const& b){
		return a.i < b.i;
	});

	forn(i,Q)
		printf("%d\n", queries[i].result);
		// cout << queries[i].result << '\n';

	return 0;
}
