// Code presented as originally written in-contest.

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;


#define forn(i,n) for(int i = 0; i < int(n); ++i)


constexpr int maxn = 1 << 19;
constexpr int stsize = 1 << 20;

int D;

long long pot (long long b, long long n) {
	assert(n >= 0);
	long long res = 1;
	while(n){
		if(n % 2) res = (res * b) % D;
		b = (b * b) % D;
		n = n / 2;
	}
	return res;
}

struct Monoid {
	int digitos;
	int valor_mod_d;

	static Monoid id () {
		return {0, 0};
	}
};

Monoid operator + (Monoid const& lhs, Monoid const& rhs) {
	int digitos = lhs.digitos + rhs.digitos;
	long long potv = pot(10, rhs.digitos);
	int lval = (potv * lhs.valor_mod_d) % D;
	int valor_mod_d = (lval + rhs.valor_mod_d) % D;
	return {digitos, valor_mod_d};
}


Monoid st [stsize];

int qa, qb;
Monoid query_impl (int i, int a, int b) {
	if(qa <= a && b <= qb) return st[i];
	if(b <= qa || qb <= a) return Monoid::id();
	int m = (a+b)/2;
	return query_impl(i*2, a, m) + query_impl(i*2+1, m, b);
}
int query (int a, int b) {
	qa = a;
	qb = b;
	return query_impl(1, 0, maxn).valor_mod_d;
}
void update (int i, int x) {
	i += maxn;
	st[i] = {1, x};
	while(i /= 2) st[i] = st[i*2] + st[i*2+1];
}
void unsafe_assign (int i, int x) {
	i += maxn;
	st[i] = {1, x};
}
void init () {
	for(int i = maxn-1; i > 0; i--){
		st[i] = st[i*2] + st[i*2+1];
	}
}



vector<int> dominando(string n, int d, vector<int> t, vector<int> a, vector<int> b)
{
	D = d;
	forn(i, n.size())
		unsafe_assign(i, n[i] - '0');
	init();

	vector<int> ret;
	ret.reserve(t.size());
	forn(i, t.size()){
		if(t[i] == 0){ // query
			int result = query(a[i]-1, b[i]);
			ret.push_back(result);
		} else { // update
			update(a[i]-1, b[i]);
		}
	}

	return ret;
}

/*
#ifdef EVAL
int main () {
	D = 10000000;
	Monoid a = Monoid::id() + Monoid{1,2} + Monoid::id();
	Monoid b = Monoid::id() + Monoid{2,94} + Monoid::id();;
	Monoid c = Monoid::id() + Monoid{2,56} + Monoid::id();;
	Monoid d = a + b + c + Monoid::id();;
	cerr << d.valor_mod_d;
}
#endif
*/

#ifndef EVAL
    #include <iostream>

    int main() {
        string n;
        int d;
        cin >> n >> d;
        int q;
        cin >> q;
        vector<int> t, a, b;
        t.reserve(q);
        a.reserve(q);
        b.reserve(q);
        for (int i=0;i<q;i++) {
            int tValue, aValue, bValue;
            cin >> tValue >> aValue >> bValue;
            t.push_back(tValue);
            a.push_back(aValue);
            b.push_back(bValue);
        }
        vector<int> ret = dominando(n, d, t, a, b);
        for (int x : ret)
            cout << x << endl;
    }
#endif
