#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
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

const ll MAXN = 110;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

vector<int> tablita(string s) {
	int n = (int)s.size();
	vector<int> result(n,0);

	forn(i,n){
		forr(corro,1,i+1){
			int lon = i - corro;
			bool puedo = true;
			forn(j,lon) {
				if(s[j] != s[j+corro])
					puedo = false;
			}
			if (puedo) {
				result[i] = lon;
				break;
			}
		}
	}

	forr(i,1,n) assert(result[i] < i);

	return result;
}

vector<int> T;
string s1, s2, virus;

int memo[MAXN][MAXN][MAXN][2];
int choice[MAXN][MAXN][MAXN][2];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> s1 >> s2 >> virus;
	T = tablita(virus);

	{ int i = int(s1.size());
		forn(j, s2.size()+1) {
			forn(k, virus.size()+1) {
				forn(w, 2) {
					choice[i][j][k][w] = 0;
					memo[i][j][k][w] = 0;
				}
			}
		}
	}

	{ int j = int(s2.size());
		forn(i, s1.size()+1) {
			forn(k, virus.size()+1) {
				forn(w, 2) {
					choice[i][j][k][w] = 0;
					memo[i][j][k][w] = 0;
				}
			}
		}
	}

	{ int k = int(virus.size());
		forn(i, s1.size()+1) {
			forn(j, s2.size()+1) {
				forn(w, 2) {
					choice[i][j][k][w] = 0;
					memo[i][j][k][w] = -5000;
				}
			}
		}
	}


	for (int i = (int)s1.size(); i--;) {
		for (int j = (int)s2.size(); j--;) {
			forn(k, virus.size()) {
				forn(w, 2) {

					int& res = memo[i][j][k][w];
					int& ch = choice[i][j][k][w];

					auto mejorar = [&](int val, int decido) {
						if (res < val) {
							res = val;
							ch = decido;
						}
					};

					ch = 0;
					res = 0;

					if (w == 1) {
						mejorar(memo[i+1][j][k][1], 1);
						mejorar(memo[i][j+1][k][1], 2);
						mejorar(memo[i][j][k][0], 3);
					} else if (s1[i] == s2[j]) {
						if (s1[i] == virus[k]) {
							mejorar(1+memo[i+1][j+1][k+1][1], 4);
						} else if (k > 0) {
							mejorar(memo[i][j][T[k]][0], 5);
						} else {
							mejorar(1+memo[i+1][j+1][0][1], 6);
						}
					}

				}
			}
		}
	}

	int cant = memo[0][0][0][1];
	if (cant <= 0) {
		cout << "0\n";
		return 0;
	}

	string ans;
	int i = 0;
	int j = 0;
	int k = 0;
	int w = 1;
	forn(asdasd, 1200000) {
		int ch = choice[i][j][k][w];
		cerr << "===================\n";
		db(ch);
		db(i);
		db(j);
		db(k);
		if (ch == 0) {
			break;
		} else if(ch == 1) {
			i += 1;
			w = 1;
		} else if(ch == 2) {
			j += 1;
			w = 1;
		} else if(ch == 3) {
			w = 0;
		} else if(ch == 4) {
			ans.pb(s1[i]);
			i += 1;
			j += 1;
			k += 1;
			w = 1;
		} else if(ch == 5) {
			k = T[k];
			w = 0;
		} else {
			ans.pb(s1[i]);
			i += 1;
			j += 1;
			k = 0;
			w = 1;
		}
	}

	cout << ans << '\n';


    return 0;
}
