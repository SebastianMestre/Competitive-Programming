#include <bits/stdc++.h>
using namespace std;

#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
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

void solve() {
	int n;
	cin >> n;

	vector<pii> ps(n);
	forn(i,n) cin >> ps[i].fst >> ps[i].snd;
	forn(i,n) ps[i].fst--;

	vector<int> perm(n);
	forn(i,n) perm[i] = i;
	sort(all(perm), [&](int i, int j) {
		return ps[i] < ps[j];
	});

	vector<int> coloring(n, -1);

	priority_queue<pii> events;

	priority_queue<int> colors;
	forn(i,n) colors.push(-i);

	for (int i : perm) {
		while (not events.empty() && -events.top().fst <= ps[i].fst) {
			auto evt = events.top(); events.pop();
			int c = evt.snd;
			colors.push(-c);
		}

		int c = -colors.top();
		colors.pop();
		coloring[i] = c;
		events.push({-ps[i].snd, c});
	}

	auto mv = *max_element(all(coloring));
	cout << mv+1 << '\n';
	for (int x : coloring) cout << (x+1) << ' ';
	cout << '\n';
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	solve();

    return 0;
}
