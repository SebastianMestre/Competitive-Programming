#include <iostream>
#include <set>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forrn(i,n) for(int i = int(n)-1; i >= 0; --i)

using namespace std;

using ll = long long;

constexpr ll INF = 1ll<<50; // 1e15
constexpr int MOD = 1000000007; // 1e9+7

const int maxn = 100000;
const int maxk = 100000;

set<int> likers[maxn];
set<int> likes[maxk];
set<int> options_2;
set<int> options_1;
set<int> options_0;

int main () {

	int n, k;
	cin >> n >> k;

	forn(i,k){
		int x,y;
		cin>>x>>y;
		--x;--y;
		likes[i].insert(x);
		likes[i].insert(y);
		likers[x].insert(i);
		likers[y].insert(i);
		options_2.insert(i);
	}

	int ended_at = k;
	forn(i,k){
		int person = -1;
		if(!options_1.empty()){
			auto it = options_1.begin();
			person = *it;
			options_1.erase(it);
		} else if(!options_2.empty()){
			auto it = options_2.begin();
			person = *it;
			options_2.erase(it);
		}

		if(person == -1){
			ended_at = i;
			break;
		}

		// cerr << "@ person " << person << '\n';
		// options_0.insert(person);
		for(int snack : likes[person]) {
			// cerr << "@@ snack " << snack << '\n';
			for(int other : likers[snack]){
				// cerr << "@@@ other " << other << '\n';
				if(options_2.count(other)){
					// cerr << "@@@ moved to lvl 1\n";
					options_2.erase(other);
					options_1.insert(other);
				} else if (options_1.count(other)){
					// cerr << "@@@ moved to lvl 0\n";
					options_1.erase(other);
					options_0.insert(other);
				}
			}
			likers[snack].clear();
		}
	}

	cout << options_0.size() << '\n';
	// cout << (k-ended_at) << '\n';
}

