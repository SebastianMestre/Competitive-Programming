#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
#define forr(i,n) for(int i = n; i--;)

using namespace std;

int main () {

int n;
cin >> n;

int maxbalance = 100;
int balance = 100;

for(int i = 0; i < n; ++i){
	int b;
	cin >> b;

	balance += b;
	maxbalance = max(maxbalance, balance);
}

cout << maxbalance << '\n';

}
