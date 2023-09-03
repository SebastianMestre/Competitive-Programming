#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=(a);i<(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) // cerr<<#v" = "<<(v)<<'\n'
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

const ll MAXN = 100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

char c[MAXN][MAXN];
bool v[MAXN][MAXN];

int n, m;
int cant;
void dfs(int i,int j) {
	if (c[i][j] == '.') return;
	if (v[i][j]) return;
	v[i][j] = true;
	cant += 1;
	dfs(i, j+1);
	dfs(i+1, j);
	dfs(i-1, j);
	dfs(i, j-1);
}

int get_cant() {
	memset(v, 0, sizeof(v));
	cant = 0;

	forn (x,n){
		forn(y,m){
			if (c[x][y] == '#') {
				dfs(x,y);
				return cant;
			}
		}
	}

	return 0;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> m;

	forn(i,n+2){
		forn(j,m+2){
			c[i][j] = '.';
		}
	}

	int cant0 = 0;

	forn(i,n){
		forn(j,m){
			cin >> c[i+1][j+1];
			cant0 += c[i+1][j+1] == '#';
		}
	}

	db(cant0);

	if (cant0 < 3) {
		cout << "-1\n";
		return 0;
	}

	n += 2;
	m += 2;

	forn(i,n){
		forn(j,m){
			if (c[i][j] == '.') continue;
			c[i][j] = '.';

			int cant_now = get_cant();
			db(cant_now);

			if (cant_now < cant0-1) {
				cout << "1\n";
				return 0;
			}

			c[i][j] = '#';
		}
	}

	cout << "2\n";
	return 0;
}
