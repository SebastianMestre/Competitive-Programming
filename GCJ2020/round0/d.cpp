#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i =0; i <int(n);++i)

int main () {

	int t, b;

	cin >> t >> b;

	auto query = [&](int i){
		cout << (i+1) << endl;
		int r;
		cin >> r;
		return r;
	};

	forn(ti, t){
		vector<int> values(b,-1);

		if(b == 10){
			forn(i,b) values[i] = query(i);
		} else {
			// dummy queries to get aligned
			query(0); query(0);

			int eq_idx = -1;
			int df_idx = -1;
			int i = 0;
			for(; i+4-1 < b/2; i += 4){

				for(int o = 0; o < 4; ++o){
					int rf = query(     i+o );
					int rb = query(b-1-(i+o));

					values[     i+o ] = rf;
					values[b-1-(i+o)] = rb;

					if(rf == rb){ eq_idx = i+o;
					}else{ df_idx = i+o; }
				}

				// random effect happening now

				if(eq_idx == -1){ query(0); // dummy query to stay aligned
				}else{
					int req = query(eq_idx);
					if(req != values[eq_idx]){
						// we got negated
						cerr << "NEGATED\n";
						forn(j,b) if(values[j] != -1) values[j] = !values[j];
					}
				}

				if(df_idx == -1){ query(0); // dummy query to stay aligned
				}else{
					int req = query(df_idx);
					if(req != values[df_idx]){
						// got reversed
						cerr << "REVERSED\n";
						reverse(values.begin(), values.end());
					}
				}
			}
			cerr << "END STAGE\n";
			for(; i<b/2; i += 1){
				int rf = query(    i);
				int rb = query(b-1-i);
				values[    i]=rf;
				values[b-1-i]=rb;
			}
		}

		forn(i,b){
			cout << values[i];
		}
		cout << endl;

		string response;
		cin >> response;

		if(response == "N"){
			break;
		}
	}
    
}
