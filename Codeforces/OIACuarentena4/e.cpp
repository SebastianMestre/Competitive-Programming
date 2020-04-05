#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using lint = long long;
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

const lint maxn = 10000;
int a[maxn];

lint cost (int l, int r, int h, bool can_hor) {
	if (r-l == 0) return 0;
	if (r-l == 1) return 1;
	if (!can_hor) return r-l;

	int minv = *min_element(a+l, a+r);

	int min_count = 0;
	vector<int> indices;
	indices.push_back(l-1);
	forsn(i,l,r){
		if(a[i] == minv){
			min_count += 1;
			indices.push_back(i);
		}
	}
	indices.push_back(r);

	lint horcost = minv - h;
	forn(i,indices.size()-1){
		int li = indices[i]+1;
		int ri = indices[i+1];
		horcost += cost(li, ri, minv, true);
	}

	lint vercost = cost(l, r, h, false);

	return min(horcost, vercost);
}

int main () {
	int n;
	cin >> n;

	forn(i, n){
		cin >> a[i];
	}

	cout << cost(0,n,0,true) << '\n';
}

