#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define vecp(v) cerr<<#v<<" = "; for(auto ee:v)cerr<<ee<<' '; cerr<<'\n'
#define nn cout<<'\n'
#define sz(v) (int(v.size()))
#define all(v) v.begin(), v.end()
#define pb push_back
#define pp pop_back
#define fst first
#define snd second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll MAXN = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

unordered_map<int, int> cant;

int tipo1 = 0;

void solve()
{
    int n, k; cin >> n >> k;
    
    forn(i, n) {
        int s = 0;
        
        forn(j, k) {
            int x; cin >> x;
            s |= (x << j);
        }

		// cerr << "MASCARA " << s << "\n";
        
        cant[s] ++;
    }
    
	// un problema
    if(cant[0] >= 1) {
		// cerr << "SALE 1\n";
        cout << "YES", nn;
        return;
    }
    
	// dos tipos de problemas
	forn(m1, (1<<k)) {
		forn(m2, (1<<k)) {
			if (m1 &  m2) continue;
			if (!cant[m1]) continue;
			if (!cant[m2]) continue;
		// cerr << "SALE 2\n";
		// cerr << m1 << " --- " << m2 << "\n";
			cout << "YES", nn;
			return;
		}
	}
    
    if(cant[1] >= 1)      tipo1 = 1;
    else if(cant[2] >= 1) tipo1 = 2;
    else if(cant[4] >= 1) tipo1 = 4;
    else if(cant[8] >= 1) tipo1 = 8;
    
	if (tipo1 != 0) {
		cout << "NO", nn;
		return;
	}


	int mascaras_tipo2[6] = {
		(2+1), (4+1), (8+1),
		(4+2), (8+2),
		(8+4),
	};
	forn (x, (1<<6)) {
		if (x == 0) continue;
		bool puedo = true;
		int cant_jugador[4];
		forn (i, 6) {
			if ((x & (1<<i)) == 0) continue;
			int m = mascaras_tipo2[i];
			if (!cant[m]) {
				puedo = false;
				break;
			}
			forn (j, 4) {
				if (m & (1 << j)) {
					cant_jugador[j] += 1;
				}
			}
		}
		if (!puedo) continue;
		forn (j, 4) {
			if (cant_jugador[j]*2 > __builtin_popcount(x)) {
				puedo = false;
				break;
			}
		}
		if (!puedo) continue;
		// cerr << "SALE 3\n";
		cout << "YES", nn;
		return;
	}

	cout << "NO", nn;
    
}




//___________________________

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
