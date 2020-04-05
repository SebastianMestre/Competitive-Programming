#include <iostream>
#include <deque>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 500;
int a[maxn];
int main () {

	int n;
	long long k;
	cin >> n >> k;

	forn(i,n){
		cin >> a[i];
	}

	if(k >= n-1){
		cout << n << '\n';
		return 0;
	}

	deque<int> fight;
	forn(i,n){ fight.push_back(a[i]); }

	int winner = fight.front();
	int consecutive = 0;
	while(1){
		int fighter1 = fight.front();
		fight.pop_front();
		int fighter2 = fight.front();
		fight.pop_front();

		int wins = max(fighter1, fighter2);
		int lose = min(fighter1, fighter2);

		if(wins == winner){
			consecutive += 1;
		} else {
			consecutive = 1;
			winner = wins;
		}

		if(consecutive == k){
			break;
		}

		fight.push_front(wins);
		fight.push_back(lose);
	}

	cout << winner << '\n';
}

