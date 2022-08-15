#include <cstdio>
#include <cstring>
#include <algorithm>

constexpr int maxn = 5000;
using ll_t = long long;

ll_t dp[maxn+1][maxn+1];
int x[maxn];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n ; ++i)
		scanf("%d", &x[i]);
	for (int i = n+1; i-- > 0;) {
		dp[i][i] = 0;
		dp[i][i+1] = x[i];
		for (int j = i+2; j < n+1; ++j) {
			ll_t l = x[i] + std::min(dp[i+2][j], dp[i+1][j-1]);
			ll_t r = x[j-1] + std::min(dp[i+1][j-1], dp[i][j-2]);
			dp[i][j] = std::max(l, r);
		}
	}
	printf("%lld\n", dp[0][n]);
}
