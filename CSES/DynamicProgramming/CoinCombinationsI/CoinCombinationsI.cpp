#include<iostream>
#include<algorithm>
#define L(i,n) for(int i=0;i<int(n);++i)
#define LS(i,s,n) for(int i=s;i<int(n);++i)
constexpr int maxx = 1000001;
constexpr int maxn = 101;
constexpr int MOD = 1000000007;
int dp[maxx];
int c[maxn];

int main () {
	int n,x;
	scanf("%d%d",&n,&x);
	L(i,n){ scanf("%d",c+i); }

	dp[0] = 1;
	LS(j,1,x+1){
		L(i,n){
			if(c[i] <= j) {
				dp[j] += dp[j-c[i]];
				dp[j] %= MOD;
			}
		}
	}

	printf("%d\n",dp[x]);
}
