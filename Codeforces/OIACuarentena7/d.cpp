#include <iostream>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>


#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

int main () {
	int n;
	cin >> n;

	unordered_map<int,int> front;
	unordered_map<int,int> back;
	unordered_map<int,int> same;
	unordered_set<int> colors;

	forn(i,n){
		int f,b;
		cin >> f >> b;
		front[f] += 1;
		back[b] += 1;
		if(f == b) same[f] += 1;
		colors.insert(f);
		colors.insert(b);
	}

	const int half = (n+1)/2;
	int minres = n+1;
	for(int c : colors){
		int f = front[c];
		int b = back[c];
		int s = same[c];

		if(f+b-s >= half){
			int total = half;
			total -= f;
			total = max(total, 0);
			minres = min(minres, total);
		}
	}

	if(minres == n+1) minres = -1;
	cout << minres<<'\n';

}

