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


struct state { char n, a, b, c; };

static_assert(sizeof(state) == 4, "COME ON NOW");

char const* response[17] = { "0\n", "1\n", "3\n", "7\n", "15\n", "31\n", "63\n", "127\n", "255\n", "511\n", "1023\n", "2047\n", "4095\n", "8191\n", "16383\n", "32767\n", "65535\n" };
int length  [17] = {  2 ,  2 ,  2 ,  2 ,  3  ,  3  ,  3  ,  4   ,  4   ,  4   ,  5    ,  5    ,  5    ,  5    ,  6     ,  6     ,  6      };
char* cursor;
char to_print[4 * (1<<16) + 128];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;

	fwrite_unlocked(response[n], 1, length[n], stdout);

	cursor = to_print;
	state pila[32];
	int top = 0;
	pila[top++] = {n,'1','2','3'};
	while (top) {
		state s = pila[--top];
		if (s.n == 1) {
			*cursor++ = s.a; *cursor++ = ' '; *cursor++ = s.c; *cursor++ = '\n';
		} else {
			pila[top++] = {s.n-1, s.b, s.a, s.c };
			pila[top++] = {1,     s.a, s.b, s.c };
			pila[top++] = {s.n-1, s.a, s.c, s.b };
		}
	}
	fwrite_unlocked(to_print, 1, cursor-to_print, stdout);
    
    return 0;
}
