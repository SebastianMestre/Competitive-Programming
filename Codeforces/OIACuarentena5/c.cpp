#include<iostream>
#define forn(i,n)for(int i=0;i<int(n);++i)
using namespace std;
using ll=long long;
const int maxn=100000;
int a[2][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	forn(j,2)forn(i,n)cin>>a[j][i];
	ll v[2]={};
	forn(i,n){
		ll u[2];
		forn(j,2)u[j]=max(v[j],a[j][i]+v[!j]);
		forn(j,2)v[j]=u[j];
	}
	cout<<max(v[0],v[1])<<'\n';
}
