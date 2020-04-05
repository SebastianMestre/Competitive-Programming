#include <iostream>
#include <map>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 200000;
map<int, int> a;

int main () {
int n;
	ll T;
	cin >> n >> T;

	ll total = 0;
	ll minv = INF;
	ll plata = T;
	ll ans = 0;
	ll puestos = n;

	forn(i,n){
		int ai;
		cin >> ai;
		a[i] = ai;
		total += ai;
		minv = min(minv, (ll)ai);
	}

	while(plata >= minv){
		for(auto it = a.begin(); it != a.end();){
			if(plata < minv) break;

			if(plata >= total){
				ll vueltas = plata / total;
				ans += vueltas * puestos;
				plata = plata % total;
				if(plata < minv) break;
			}

			auto [k,v] = *it;

			// cerr << "@@ k="<<k<<" v="<<v<<" plata="<<plata<<'\n';

			// no me alcanza para el producto
			// entonces nunca me va a alcanzar
			if(v > plata){
				// cerr << "--- SALTEO\n";
				total -= v;
				puestos -= 1;

				if(plata >= total){
					// cerr << "--- VUELTA\n";
					ll vueltas = plata / total;
					ans += vueltas * puestos;
					plata = plata % total;
					if(plata < minv) break;
				}

				a.erase(it);
				if(a.size() == 0) break;
				it = a.lower_bound(k);
			} else {
				// cerr << "--- COMPRO\n";
				plata -= v;
				ans += 1;
				++it;
				if(plata < minv) break;
			}
		}
	}

	cout << ans << '\n';
}

