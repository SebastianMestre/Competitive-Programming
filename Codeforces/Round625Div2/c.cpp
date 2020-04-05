#include <iostream>
#include <vector>
#include <algorithm>

// POST-CONTEST

using namespace std;

const int maxn = 100;
const int INF = 1<<29;

#define forn(i,n) for(int i = 0; i< int(n); ++i)

int main () {
	int n;
	string s;
	cin >> n >> s;

	int count = 0;

	while(1){
		char rem_c = 0;
		int  rem_i = -1;
		forn(i,n){
			if(i!=0) if(s[i-1] == s[i]-1) {
				if(rem_c < s[i]){
					rem_c = s[i];
					rem_i = i;
				}
			}
			if(i!=n-1) if(s[i+1] == s[i]-1) {
				if(rem_c < s[i]){
					rem_c = s[i];
					rem_i = i;
				}
			}
		}

		if(!rem_c) break;

		rotate(s.begin() + rem_i, s.begin() + rem_i + 1, s.end());
		s.pop_back();
		count += 1;
	}

	cout << count << '\n';
}
