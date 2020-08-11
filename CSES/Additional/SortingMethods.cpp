#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0; i< int(n); ++i)
#define forsn(i,s,n) for(int i = s; i< int(n); ++i)
#define forr(i,n) for(int i = n; i--;)
constexpr int maxn = int(2e5) + 1;

using ll = long long;

int n;
int a[maxn]; // permutation
int b[maxn]; // inverse permutation

ll inv(int const l, int const r, int* b1, int* b2){
	if(r-l < 2) return 0;
	ll res = 0;
	int const m = (l+r)/2;
	res += inv(l,m,b1,b2);
	res += inv(m,r,b1,b2);
	int k = l;
	int i = l;
	int j = m;
	while(i < m && j < r)
		if(b1[i] < b1[j]) b2[k++] = b1[i++], res += j-m;
		else              b2[k++] = b1[j++];
	while(i < m) b2[k++] = b1[i++], res += j-m;
	while(j < r) b2[k++] = b1[j++];
	forsn(q,l,r) b1[q] = b2[q];
	return res;
}

// cada swap borra una inversion, asique la cantidad de swaps
// es igual a la cantidad de inversiones
ll ans1() {
	int* b1 = new int[n];
	int* b2 = new int[n];
	forn(i,n) b1[i] = a[i];
	ll res = inv(0,n,b1,b2);
	// cerr << "@@"; forn(i,n) cerr << b1[i] << ' '; cerr << '\n';
	delete[] b2;
	delete[] b1;
	return res;
}

// la menor cantidad de swaps se encuentra usando selection
// sort. como lo que ordenamos son una permutacion, podemos
// buscar cada elemento en O(1) mirando la inversa.
int ans2() {
	vector<int> v(a,a+n);
	vector<int> w(b,b+n);
	int res = 0;
	forn(i,n){
		if(v[i] == i) continue;
		res += 1;
		int j = w[i]; // min_element(v.begin() + i, v.end()) - v.begin();
		// cerr << "@@@" << j << ' ' << v[j] << ' ' << w[v[j]] << '\n';
		swap(w[v[i]], w[v[j]]);
		swap(v[i], v[j]);
	}
	// cerr << "\n@@"; forn(i,n) cerr << v[i] << ' '; cerr << '\n';
	return res;
}

// buscas la subsecuencia ya ordenada mas larga (LIS)
// a esos los dejas en paz y al resto lo encajas entre medio
// asique te queda n-length(LIS)
int ans3() {
	vector<int> v;
	v.push_back(a[0]);
	forsn(i,1,n){
		int x = a[i];
		if (x < v[0]) {
			v[0] = x;
		} else if (x > v.back()) {
			v.push_back(x);
		} else {
			int l = 0, r = v.size()-1;
			while (r-l > 1){
				int m = (l+r)/2;
				if (x <= v[m]) r = m;
				else           l = m;
			}
			v[r] = x;
		}
	}
	return n - v.size();
}

// agarramos la subsecuencia mas larga de numeros
// consecutivos que incluye (n-1)
// A esos no los vamos a tocar, al resto los movemos al
// inicio del array en el orden correcto.
int ans4() {
	int k = n-1;
	for(;k && b[k] > b[k-1]; --k);
	return k;
}

int main () {
	cin >> n;
	forn(i,n) cin >> a[i];
	forn(i,n) a[i] -= 1;
	forn(i,n) b[a[i]] = i;

	cout << ans1() << ' ';
	cout << ans2() << ' ';
	cout << ans3() << ' ';
	cout << ans4() << '\n';
}
