#include <vector>

using namespace std;

const int INF = 1e9;

vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia)
{
    vector<int> ret;

    for(int i = 0; i < E; ++i){
        autonomia[i] += ubicacion[i];
    }

    autonomia[E-1] = INF;

	int chequeado = 0;
	for(int i = 0; i != E;) {
		int mejor = i;
		for(int j = chequeado; j < E && ubicacion[j] <= autonomia[i]; ++j) {
			chequeado = j;
			if(autonomia[mejor] < autonomia[j])
				mejor = j;
		}
		if(i == mejor) return {};
		i = mejor;

		ret.push_back(ubicacion[i]);
	}

    return ret;
}
