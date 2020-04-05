#include <iostream>
#include <vector>
#include <algorithm>

#include <cassert>

#define forn(i,n) for(int i =0 ; i < int(n); ++i)

using namespace std;

int main () {
	int N;
	cin >> N;

	vector<int> maxs(N, 0);
	vector<int> mins(N, 1000000);
	vector<bool> asc(N, false);
	int asc_count = 0;

	forn(i,N){
		int l;
		cin >> l;

		forn(j, l){
			int x;
			cin >> x;

			if(mins[i] < x) asc[i] = true;
			maxs[i] = max(maxs[i], x);
			mins[i] = min(mins[i], x);
		}

		if(asc[i]) asc_count++;
	}

	int clean_count = N - asc_count;
	vector<int> mins_clean(clean_count);
	vector<int> maxs_clean(clean_count);

	{
		int j = 0;
		forn(i, N){
			if(not asc[i]){
				mins_clean[j] = mins[i];
				maxs_clean[j] = maxs[i];
				j += 1;
			}
		}
		assert(j == clean_count);
	}

	sort(maxs_clean.begin(), maxs_clean.end());

	long long result = 0;

	// los q tienen un ascenso dan true con todos
	result += 1ll * asc_count * N;

	// los q no tienen ascenso dan true con los que si
	result += 1ll * clean_count * asc_count;

	// el resto se chequea asi:
	forn(i, clean_count){
		// tomando uno sin ascenso como primero
		// va a haber ascenso si hay alguno en el otro que sea mas grande
		// que alguno en este.
		// En particular, si el maximo del otro es mas grande que el minimo
		// de este.
		// Podemos encontrar cuantos hay si tenemos los maximos ordenados
		// usando busqueda binaria

		auto found = upper_bound(maxs_clean.begin(), maxs_clean.end(), mins_clean[i]);
		int greater_count = distance(found, maxs_clean.end());
		
#ifdef DEBUG
		{
			int brute = 0;
			forn(j, N){ if(mins_clean[i] < maxs_clean[j]) { brute += 1; } }
			assert(brute == greater_count);
			cerr << "there are " << greater_count << " with max greater than " << mins_clean[i] << " and no ascents" << '\n';
		}
#endif

		result += greater_count;
	}


	cout << result << '\n';
}
