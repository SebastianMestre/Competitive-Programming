#include <iostream>
#include <cstdint>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

int mod (int a, int b) {
	return (a>=0?a:b-(-a)%b)%b;
}

int sliding_solution(int a, int b, int t, string const& s){
	t -= 1+(s[0]=='w'?b:0);
	if(t < 0) return 0;
	if(s.size() == 1) return 1;

	int solution = 1;

	// [i,j) range
	int i = 0;
	int j = 1;

	while(1){
		int ext = 1 + a + a + (s[mod(j, s.size())]=='w'?b:0);
		if(t < ext) break;
		if(j == s.size()) break;
		t -= ext;
		++j;
	}

	{
		int len = j-i;
		solution = max(solution, len);
	}

	for(; j > 0; --j){
		while(1){
			int ext = 1 + a + (s[mod(i-1,s.size())]=='w'?b:0);
			if(t < ext) break;
			if(mod(i,s.size()) == mod(j,s.size()) && i != j) break;
			t -= ext;
			--i;
		}

		int len = j-i;
		solution = max(solution, len);

		int svt = 1+a+a+(s[mod(j-1,s.size())]=='w'?b:0);
		t += svt;
	}

	return solution;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b, t;
	cin >> n >> a >> b >> t;

	string s;
	cin >> s;

	int solution = sliding_solution(a, b, t, s);

	reverse(s.begin(), s.end());
	rotate(s.begin(), s.end()-1, s.end());
	solution = max(solution, sliding_solution(a, b, t, s));

	cout << solution << '\n';
}

