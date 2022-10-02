#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 100000;

bool is_digit(char c) {
	return ('0' <= c) & (c <= '9');
}

int get_int(){
	int result = 0;
	char c;
	while (is_digit(c = getchar_unlocked())) {
		result *= 10;
		result += c-'0';
	}
	return result;
}

char* put_int(char* l, int x) {
	if (x == 0) {
		*l = '0';
		return l+1;
	}

	char* r = l;
	while (x) {
		*r = char('0' + x%10);
		x /= 10;
		r++;
	}
	char* end = r;
	--r;
	while (l < r) {
		swap(*l, *r);
		++l; --r;
	}
	return end;
}


int uf[MAXN];
int cant_com;

int uf_find(int i) {
	while (uf[i] != i)
		i = uf[i] = uf[uf[i]];
	return i;
}

void uf_join(int i, int j) {
	i = uf_find(i);
	j = uf_find(j);
	cant_com -= i != j;
	uf[i] = j;
}

using pii = pair<int,int>;

int main() {
	int n, m;
	n = get_int();
	m = get_int();
	for (int i = 0; i < n; ++i)
		uf[i] = i;
	cant_com = n;

	for (int i = 0; i < m; ++i) {
		int u, v;
		u = get_int();
		v = get_int();
		--u; --v;
		uf_join(u, v);
	}

	char buf[100];
	{
		char* c = buf;
		c = put_int(c, cant_com-1);
		*c = '\n'; ++c;
		fwrite_unlocked(buf, 1, c-buf, stdout);
	}

	int prev = -1;
	int i = 0;
	for(; i < n; ++i) {
		if (uf[i] == i) {
			prev = i;
			i++;
			break;
		}
	}

	for(; i < n; ++i) {
		if (uf[i] == i) {
			char* c = buf;
			c = put_int(c, prev+1);
			*c++ = ' ';
			c = put_int(c, i+1);
			*c++ = '\n';
			fwrite_unlocked(buf, 1, c-buf, stdout);
			prev = i;
		}
	}

}
