#include <bits/stdc++.h>
using namespace std;

#define db(v) cerr<<#v" = "<<(v)<<'\n'

typedef long long ll;

const ll MOD = 1e9+7;

int modu(ll x) { return x % MOD; }
int add(ll x, ll y) { return  modu(x+y); }
int mul(ll x, ll y) { return  modu(x*y); }
int sub(ll x, ll y) { return modu(modu(x-y) + MOD); }
int pot(ll x, ll n) { ll acc = 1; while (n) { if (n&1) acc = mul(acc, x); x = mul(x, x); n /= 2; } return acc; }
int inv(ll x) { return pot(x, MOD-2); }
int neg(ll x) { return sub(0, x); }

int pcount(int x) { return __builtin_popcount(x); }

void sort3(int& i, int& j, int& k) {
	if (i > j) swap(i, j);
	if (j > k) swap(j, k);
	if (i > j) swap(i, j);
}

int calc_most_sig(int k) {
	int idx = 0;
	while ((1ll<<(idx+1)) <= k) idx++;
	return idx;
}

bitset<32> binario(int x) { return {x}; }

int count_lose_fast(int i, int j, int k) {
	sort3(i, j, k);

//	db(binario(i));
//	db(binario(j));
//	db(binario(k));

	if (i == 0) {
		return min(j, k) + 1;
	}

	int most_sig_k = calc_most_sig(k); int bk = 1ll<<most_sig_k;
	int most_sig_j = calc_most_sig(j); int bj = 1ll<<most_sig_j;
	int most_sig_i = calc_most_sig(i); int bi = 1ll<<most_sig_i;

	if (most_sig_k > most_sig_j && most_sig_k > most_sig_i) {
		return count_lose_fast(i, j, bk-1);
	}

	if (most_sig_k == most_sig_j && most_sig_k > most_sig_i) {
		if (k == j && pcount(k) == most_sig_k+1) {
			// en este caso bj-1==j^bj  y  bk-1==k^bk  asique las dos ramas dan lo mismo
			ll mitad = count_lose_fast(i, bj-1, bk-1);
			return add(mitad, mitad);
		}
		return add(
			count_lose_fast(i, bj-1, bk-1),
			count_lose_fast(i, j^bj, k^bk));
	}

	if (most_sig_k == most_sig_j && most_sig_k == most_sig_i) {
		if (k == j && k == i && pcount(k) == most_sig_k+1) {
			// todos los bits prendidos, hay 4 posibilidades por digito
			// la respuesta es pot(4, Longitud)
			ll raiz = modu(1ll<<pcount(k));
			return mul(raiz, raiz);
		}

		return add(add(add(
			count_lose_fast(i^bi, j^bj, bk-1),
			count_lose_fast(i^bi, bj-1, k^bk)),
		    count_lose_fast(bi-1, j^bj, k^bk)),
			count_lose_fast(bi-1, bj-1, bk-1));
	}

}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

	int l1,r1,l2,r2,l3,r3;
	cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;

	int rango = mul(mul(sub(r1+1, l1), sub(r2+1, l2)), sub(r3+1, l3));

	int lose111 = count_lose_fast(r1, r2, r3);

	int lose110 = count_lose_fast(r1, r2, l3-1);
	int lose101 = count_lose_fast(r1, l2-1, r3);
	int lose011 = count_lose_fast(l1-1, r2, r3);

	int lose100 = count_lose_fast(r1, l2-1, l3-1);
	int lose010 = count_lose_fast(l1-1, r2, l3-1);
	int lose001 = count_lose_fast(l1-1, l2-1, r3);

	int lose000 = count_lose_fast(l1-1, l2-1, l3-1);

	int losetotal = add(add(add(add(add(add(add(
		lose111,
		neg(lose110)),
		neg(lose101)),
		neg(lose011)),
		lose100),
		lose010),
		lose001),
		neg(lose000));

	int wintotal = sub(rango, losetotal);

	int result = mul(wintotal, inv(rango));

	cout << result << '\n';
    
    return 0;
}
