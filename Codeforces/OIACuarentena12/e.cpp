#include <iostream>
#include <cassert>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

int w, x;

struct state {
	ll a, b, c;

	state after ( ll t ) {
		if(t==0) return *this;

		state o = *this;

		o.c -= t;
		o.b -= x * (t-1);

		ll y = -(o.b - x);
		ll steps = min(t, (y+w-1)/w);

		o.b += w * steps;
		o.a -= steps;

		o.b -= x;

		return o;
	}

	bool done () {
		return c <= a;
	}
};

int main () {

	ll a, b, c;
	cin >> a >> b >> w >> x >> c;
	state s = {a,b,c};

	ll endt = 1;
	while(not s.after(endt).done()){
		endt += endt;
	}

	ll lo = -1;
	ll hi = endt;
	while(hi-lo > 1){
		ll m = (hi+lo)/2;
		if(s.after(m).done()){
			hi = m;
		}else{
			lo = m;
		}
	}

	cout << hi << '\n';
}

