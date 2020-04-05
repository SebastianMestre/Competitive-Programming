#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)
 
long long gcd (long long a, long long b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
 
int main () {
	long long n;
	cin >> n;
 
	long long g = n;
	for(long long x = 2; x*x <= n; ++x){
		if(n % x == 0){
			g = gcd(g, x);
			g = gcd(g, n/x);
		}
	}
 
	cout << g << '\n';
}
