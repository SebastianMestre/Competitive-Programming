#include <iostream>

using namespace std;

// STAUS: WA

const int maxn = 200000;
const int INF = 1<<29;
const int stsize = 1<<20;
const int stlen = 1>>19;

int st1[stsize];
int st2[stsize];

#define forn(i,n) for(int i = 0; i< int(n); ++i)

void update (int *st, int i, int x) {
	i += stlen;
	st[i] = x;
	while(i/=2){
		st[i] = st[i*2] + st[i*2+1];
	}
}

int qa, qb;
int iquery (int* st, int i, int a, int b){
	if(b <= qa || qb <= a) return 0;
	if(qa <= a && b <= qb) return st[i];

	int m = (a+b)/2;
	return iquery(st, i*2, a, m) + iquery(st,i*2+1, m, b);
}

int query (int* st, int a, int b){
	qa = a; qb = b;
	return iquery(st, 1, 0, stlen);
}

int main () {
	int n;
	string s;

	cin >> n;
	cin >> s;

	forn(i, n){
		update(st1, i, s[i]=='1');
	}

	forn(i, n-1){
		update(st2, i, s[i]=='1' && s[i+1]=='1');
	}

	int q;
	cin >> q;

	forn(i, q){
		int a, b, len;
		cin >> a >> b >> len;
		--a; --b;

		int r1 = query(st1, a, a+len);
		int r2 = query(st1, b, b+len);

		int p1 = query(st2, a, a+len-1);
		int p2 = query(st2, b, b+len-1);

		if(s[a+len-1] == '1' && s[a+len] == '1') p1 -=1;
		if(s[b+len-1] == '1' && s[b+len] == '1') p2 -=1;

		cout << (r1 == r2 && p1 == p2 ? "Yes" : "No") << '\n';
	}
}
