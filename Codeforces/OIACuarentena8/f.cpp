#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

constexpr int INF = 1<<25; // 33e6
constexpr int MOD = 1000000007; // 1e9+7

struct vec {
	int x, y;

	vec operator + (vec const& o) const {
		return {x+o.x, y+o.y};
	}

	vec operator - (vec const& o) const {
		return {x-o.x, y-o.y};
	}

	int operator * (vec const& o) const {
		return x*o.x + y*o.y;
	}

	int operator ^ (vec const& o) const {
		return x*o.y - y*o.x;
	}

	vec operator * (int o) const {
		return {x*o, y*o};
	}

	int cuadrant () const {
		return y<0?(x<0?3:4):(x<0?2:1);
	}

	bool operator < (vec const& o) const {
		int ct = cuadrant();
		int co = o.cuadrant();
		if(ct != co) return ct < co;
		return ((*this) ^ o) > 0;
	}
};

bool back_aligned (vec a, vec b) {
	return (a^b)==0 && (a*b)<=0;
}

int main () {

	int n;
	cin >> n;
	vector<vec> points(n);

	forn(i,n){
		cin >> points[i].x >> points[i].y;
	}

	if(n<3){
		cout << 0 << '\n';
		return 0;
	}

	if(n==3){
		vec d1 = points[1] - points[0];
		vec d2 = points[2] - points[0];
		if((d1^d2)==0){
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n';
		}
		return 0;
	}

	long long aligned_count = 0;
	forn(i,n){

		// cerr << "\n** " << "{"<<points[i].x<<", "<<points[i].y<<"}"<<'\n';
		vector<vec> sorted;
		sorted.reserve(n-1);
		forn(j,n){
			if(i==j)continue;
			sorted.push_back(points[j]-points[i]);
		}

		sort(sorted.begin(), sorted.end());

		// cerr << '\n';
		// sliding window
		int b=0;
		forn(a, sorted.size()){
			// cerr << "@@ " << "{"<<sorted[a].x<<", "<<sorted[a].y<<"}"<<'\n';
			int steps = 0;
			auto sinv = sorted[a] ^ sorted[b];
			auto cosv = sorted[a] * sorted[b];
			while((steps<sorted.size())&&(sinv>0||(sinv==0&&cosv>0))){
				++steps;
				++b;
				if(b==sorted.size())b=0;

				sinv = sorted[a] ^ sorted[b];
				cosv = sorted[a] * sorted[b];
			}
			int bf = b;
			while((steps<sorted.size())&&back_aligned(sorted[a], sorted[b])){
				// cerr << "!! " << "{"<<sorted[a].x<<", "<<sorted[a].y<<"}"<<'\n';
				// cerr << "!! " << "{"<<sorted[b].x<<", "<<sorted[b].y<<"}"<<'\n';
				// cerr << "*"<<a<<' '<<b<<"\n";
				aligned_count += 1;
				++steps;
				++b;
				if(b==sorted.size())b=0;
			}
			b = bf;
		}

	}

	long long N = n;
	long long nchoose3 = N*(N-1)*(N-2)/6;
	// cerr << "CHOOSE=" << nchoose3 << '\n';
	// cerr << "ACOUNT=" << aligned_count << '\n';
	cout << (nchoose3-aligned_count/2) << '\n';
}

