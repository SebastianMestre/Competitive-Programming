#include <iostream>
#include <map>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

using pii = pair<int, int>;

int main () {

	int n;
	cin >> n;

	int alltimed = 0;
	int alltimei = -1;
	int alltimej = -1;

	map<pair<int,int>, pii> m;

	forn(i,n){
		int a,b,c;
		cin>>a>>b>>c;
		if(b<a)swap(a,b);
		if(c<b)swap(b,c);
		if(b<a)swap(a,b);

		{
			int myd = min(a,min(b,c));
			if(myd > alltimed){
				alltimed = myd;
				alltimei = i;
				alltimej = -1;
			}
		}

		if(m.count({b,c})){
			auto [ma, mi] = m[pii{b,c}];

			int newa = a + ma;
			int newd = min(newa,min(b,c));

			if(newd > alltimed){
				alltimed = newd;
				alltimei = mi;
				alltimej = i;
			}

			if(ma < a){
				m[pii{b,c}] = pii{a,i};
			}
		} else {
			m[pii{b,c}] = pii{a,i};
		}
	}
	
	if(alltimej != -1){
		cout << 2 << '\n' << (alltimei+1) << ' ' << (alltimej+1) <<'\n';
	} else {
		cout << 1 << '\n' << (alltimei+1) <<'\n';
	}
}

