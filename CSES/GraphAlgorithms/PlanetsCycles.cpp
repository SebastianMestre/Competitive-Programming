#include <cstdio>
#include <vector>
#include <cstdint>
using namespace std;

constexpr int maxn = 2e5;
constexpr int BIG = 3e5;

int round_id = 0;
int end_path = 0;

struct datapoint {
	uint64_t visited:18;
	uint64_t path:18;
	uint64_t child:18;
};
datapoint datas[maxn];

int stack[maxn];
int stack_idx = 0;

static void dfs(int u) {
	stack_idx = 0;
	while(1){
		datas[u].visited = round_id;
		int v = datas[u].child;
		if (datas[v].visited) {
			if (datas[v].visited == round_id) {
				end_path = datas[v].path;
				datas[u].child = datas[u].path - datas[v].path + 1;;
			} else {
				datas[u].child = datas[v].child + 1;
			}
			break;
		} else {
			datas[v].path = datas[u].path + 1;
			stack[stack_idx++] = u;
			u = v;
		}
	}
	while (stack_idx--) {
		u = stack[stack_idx];
		int v = datas[u].child;
		datas[u].child = datas[v].child + (datas[u].path < end_path);
	}
}

static void scan_int(int& number) { 
    number = 0; 
    for (int c = getchar_unlocked(); (c>47 && c<58); c = getchar_unlocked()) 
        number = number * 10 + c - 48; 
} 

void print_int(int number) {
	char buf[21];
	int idx = 0;
	while (number) {
		buf[idx++] = number % 10 + '0';
		number /= 10;
	}
	while (idx--) {
		putchar_unlocked(buf[idx]);
	}
}

int main () {
	int n;
	scan_int(n);
	for (int i = 0; i < n; ++i) {
		int c;
		scan_int(c);
		datas[i].child = c-1;
	}

	for (int u = 0; u < n; ++u) {
		if (!datas[u].visited) {
			round_id += 1;
			datas[u].path = 1;
			dfs(u);
			end_path = BIG;
		}
		if(u)putchar_unlocked(' ');
		print_int(datas[u].child);
	}
	putchar_unlocked('\n');

	return 0;
}
