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


struct Best
{
    ll val;
    ll min_skill;
    ll idx, i;
    
    Best(ll _val, ll _min_skill, ll _idx, ll _i)
    {
        val = _val, min_skill = _min_skill, idx = _idx, i = _i;
    }
};

int n;
ll A, cf, cm, m;
vector<pll> a;
vector<ll> need;

bool comp_snd(pll x, pll y)
{
    return x.snd < y.snd;
}

void solve()
{
    cin >> n >> A >> cf >> cm >> m;
    
    a = vector<pll>(n);
    need = vector<ll>(n);

    
    forn(i, n)
    {
        cin >> a[i].fst;
        a[i].snd = i;
    }
    
    sort(all(a));

	vector<int> perm(n);
	forn(i,n) perm[i] = i;

	sort(all(perm), [&](int i, int j) {
		return a[i] < a[j];
	});

	// forn(i,n){
	for (int i : perm | std::views::reverse) {
		cout << a[i];
	}

    
    need[0] = 0;
    forr(i, 1, n) need[i] = need[i-1] + i * (a[i].fst-a[i-1].fst);
    
    if(need[n-1] + n*(A-a[n-1].fst) <= m)
    {
        cout << cf*n + cm*A, nn;
        
        forn(i, n) cout << A << ' ';
        nn;
        
        return;
    }
    
    
    Best best(-1, -1, -1, -1);
    
    dforr(i, 1, n+1)
    {
        if(m < 0) break;
        
        int idx = upper_bound(all(need), m) - need.begin();
        idx --;
        
        idx = min(i-1, idx);
        
        assert(idx >= 0);
        
        ll min_skill = a[idx].fst + (m - need[idx]) / (idx+1);
        
        ll new_val = cf*(n-i) + cm*min_skill;
        
        if(new_val > best.val) best = Best(new_val, min_skill, idx, i);
        
        m -= A - a[i-1].fst;
    }
    
    cout << best.val, nn;
    
    forn(i, n)
    {
        if(i <= best.idx) a[i].fst = best.min_skill;
        else if(best.i <= i) a[i].fst = A;
    }
    
    sort(all(a), comp_snd);
    
    forn(i, n) cout << a[i].fst << ' ';
    nn;
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

