#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

constexpr int MOD = 1000000007;
using ll = long long;

using namespace std;

bool eq_backwards (string const& s1, string const& s2) {
	return equal(s1.cbegin(), s1.cend(), s2.crbegin());
}

bool is_palindrome (string const& s) {
	return eq_backwards(s,s);
}

int main () {
	int n,m;

	cin >> n >> m;

	vector<string> ss(n);

	forn(i,n){
		cin >> ss[i];
	}

	int totlen = 0;
	vector<string> first_part;
	vector<string> second_part;

	vector<bool> used(n,false);

	forn(i,n){
		if(used[i]) continue;
		forsn(j,i+1,n){
			if(used[j]) continue;
			if(eq_backwards(ss[i], ss[j])){
				
				totlen += m;
				totlen += m;

				first_part.push_back(ss[i]);
				second_part.push_back(ss[j]);

				used[i] = true;
				used[j] = true;

				break;
			}
		}
	}
	reverse(second_part.begin(), second_part.end());

	string p;
	forn(i,n){
		if(used[i]) continue;
		if(is_palindrome(ss[i])){
			used[i] = true;
			totlen += m;
			p = ss[i];
			break;
		}
	}

	cout << totlen << '\n';

	for(auto const& s : first_part) cout << s;
	cout << p;
	for(auto const& s : second_part) cout << s;
	cout <<'\n';
}
