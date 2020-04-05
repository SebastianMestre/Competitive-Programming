#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

using namespace std;

int main () {
	int T;
	cin >> T;

	forn(t,T){

		int n;
		cin >> n;

		vector<int> v(n);

		forn(i,n){
			cin >> v[i];
		}

		int miscount = count(v.begin(), v.end() , -1);
		if(miscount == n){
			cout << 0 << ' ' << 0 << '\n';
			continue;
		}

		if(miscount == n-1){
			int x = *find_if(v.begin(), v.end(), [](int y){return y!=-1;});
			cout << 0 << ' ' << x << '\n';
			continue;
		}

		int nomismax = -1;
		forn(i, n-1){
			if(v[i] != -1 && v[i+1] != -1){
				int delta = abs(v[i] - v[i+1]);
				nomismax = max(nomismax, delta);
			}
		}

		int maxv = -1;
		int minv = 2e9;
		forn(i, n){
			if( (i > 0 && v[i-1] == -1) || (i < n-1 && v[i+1] == -1) ) {
				if(v[i] != -1){
					maxv = max(maxv, v[i]);
					minv = min(minv, v[i]);
				}
			}
		}

		int kh = (maxv+minv+1)/2;
		int km = (maxv+minv)/2;
		int kl = (maxv+minv-1)/2;

		int mh = max(abs(maxv-kh), abs(minv-kh));
		int mm = max(abs(maxv-km), abs(minv-km));
		int ml = max(abs(maxv-kl), abs(minv-kl));

		if(ml <= min(mm, mh)) {
			cout << max(nomismax, ml) << ' ' << kl;
		} else if(mm <= min(ml, mh)) {
			cout << max(nomismax, mm) << ' ' << km;
		} else {
			cout << max(nomismax, mh) << ' ' << kh;
		}

		cout <<'\n';
	}

}
