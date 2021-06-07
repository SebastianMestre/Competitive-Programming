#include <map>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5;
int a[maxn];
int main () {
	int n, k;
	scanf("%d%d",&n,&k);
	const int THR = (k+1)/2;
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	map<int,int> H;
	int i = 0;
	for (; i < k; ++i)
		H[a[i]] += 1;
	auto it = H.begin();
	ll s = 0;
	while (s + it->second < THR)
		s += (it++)->second;
	printf("%d", it->first);
	for (; i < n; ++i){
		int j = i - k;
		auto erase_it = H.find(a[j]);
		H[a[i]] += 1;
		if(a[i] < it->first) s += 1;
		erase_it->second -= 1;
		if(a[j] < it->first) s -= 1;
		while(s + it->second < THR) { s += it->second; ++it; }
		while(s >= THR) { --it; s -= it->second; }
		printf(" %d", it->first);
		if(erase_it->second == 0)
			H.erase(erase_it);
	}
	putchar('\n');
}
