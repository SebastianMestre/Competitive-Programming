#include <iostream>
#include <cstdint>
#include <algorithm>
#include <cstring>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr uint64_t MOD = 4294967291;
constexpr int NUM = 29;
int n;

uint64_t fastmod(uint64_t n ) {
	return n % MOD;
}

bool is_palin(string const& s, int l){
	forn(i, l){
		if(s[i] != s[l-i-1])
			return false;
	}
	return true;
}

int longest_palindrome_len (string const& s){
	int l = 0;
	forsn(i, 1, s.size()){
		if(is_palin(s, i)){
			l = i;
		}
	}
	return l;
}

string longest_palindrome(string const& s){
	return s.substr(0, longest_palindrome_len(s));
}

const int maxn = 1e6 + 1;
uint64_t POTS[maxn];
uint64_t hashes [2][5001];
uint64_t backhashes [2][5001];

uint64_t potlog (uint64_t a, uint64_t n) {
	uint64_t acc = 1;
	while (n) {
		if(n % 2) {
			acc *= a;
			acc = fastmod(acc);
		}
		a *= a;
		a = fastmod(a);
		n /= 2;
	}
	return acc;
}

uint64_t reconstruct_f (int i, int j) {
	return fastmod(fastmod(hashes[0][i] * POTS[n-j]) + hashes[1][n-j]);
}

uint64_t reconstruct_b (int i, int j) {
	return fastmod(fastmod(backhashes[0][n-j] * POTS[i]) + backhashes[1][i]);
}


int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;

	forn(i, maxn){
		POTS[i] = potlog(NUM, i);
	}

	forn (t, T){
		memset(hashes, 0, sizeof(hashes));
		memset(backhashes, 0, sizeof(backhashes));
		string s;
		cin >> s;
		n = s.size();

		if(false && n == 1){
			cout << s << '\n';
			continue;
		}

		{

			// make hashes of prfixes
			uint64_t h = 0;
			hashes[0][0] = 0;
			forsn(j, 1, n+1){
				int x = (s[j-1] - 'a' + 1);
				h *= NUM;
				h += x;
				h %= MOD;
				hashes[0][j] = h;
			}

			// make hashes of suffixes
			hashes[1][0] = 0;
			forsn(i, 1, n+1){
				int x = s[n-i] - 'a' + 1;
				hashes[1][i] = hashes[1][i-1];
				hashes[1][i] += (x * POTS[i-1]) % MOD;
				hashes[1][i] %= MOD;
			}

		}

		string bs = s;
		reverse(bs.begin(), bs.end());

		{

			// make hashes of reversed prfixes
			uint64_t h = 0;
			backhashes[0][0] = 0;
			forsn(j, 1, n+1){
				int x = bs[j-1] - 'a' + 1;

				h *= NUM;
				h += x;
				h %= MOD;
				backhashes[0][j] = h;
			}

			// make hashes of reversed suffixes
			backhashes[1][0] = 0;
			forsn(i, 1, n+1){
				int x = bs[n-i] - 'a' + 1;

				backhashes[1][i] = backhashes[1][i-1];
				backhashes[1][i] += (x * POTS[i-1]) % MOD;
				backhashes[1][i] %= MOD;
			}

		}

		// pick a segment to delete to build full string
		// check that it is palindromwe by reconstructing
		// its hash from the forwards string and from the
		// backwards string.
		int bestlen = n;
		int skipi = 0;
		int skipj = n;
		forn(i, n+1){
			forsn(j, i, n+1){

				uint64_t full_hash = reconstruct_f(i, j);
				uint64_t full_hash_b = reconstruct_b(i, j);

				if(full_hash_b == full_hash){
					int len = j-i;

					if(len < bestlen){
						bestlen = len;
						skipi = i;
						skipj = j;
					}
				}
			}
		}

		// cerr << "* " << skipi << " -- " << skipj << '\n';
		// cerr << "** " << reconstruct_f(0, 0) << ' ' << reconstruct_f(3, 3) << ' ' << reconstruct_f(0, n) << '\n';
		// cerr << "** " << reconstruct_b(0, 0) << ' ' << reconstruct_b(3, 3) << ' ' << reconstruct_b(0, n) << '\n';

		// print solution
		forsn(i, 0, skipi){
			cout << s[i];
		}
		forsn(i, skipj, n){
			cout << s[i];
		}
		cout << '\n';

	}
}

