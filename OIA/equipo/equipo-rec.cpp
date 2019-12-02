#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); ++i)

struct string_view {
    char* s;
    int len;
    
	char& operator [] (int i) {
		return s[i];
	}
    string_view substr(int x, int n) {
        return {s+x,n};
    }
    bool operator < (string_view const& o) const {
        return std::lexicographical_compare(s, s+len, o.s, o.s+o.len);
    }
};

using std::vector;
using std::array;
using std::string;
using std::min;

const int maxn = 5000;

int q, p;
string_view input[5000];
char input_data[5000][501];
#ifndef SLOW
int prefijo_comun[5000];
#endif

struct range {
	int i, j, n;

	int score () const {
		return (j-i)*n*n;
	}
};

#ifdef TRACK
int calls = 0;
#endif
range f (range const r) {
#ifdef LOG
	std::cerr << "f : {["<<r.i<<", "<<r.j<<") ; "<<r.n<<" }\n";
#endif
#ifdef TRACK
	calls += 1;
#endif

	if (r.j - r.i < 2) return {0,1,-1};
	if (r.n == q) return r;

	range best = r;
	int best_score = best.score();
	for (int i = r.i; i < r.j;) {
#ifndef SLOW
		int next_n_old = q;
		int next_n = prefijo_comun[i];
#endif
		for (int j = i+1; j <= r.j; ++j) {
#ifndef SLOW
			if(j == r.j || next_n <= r.n) {
				range next = f({i, j, next_n_old});
#else
			if(j == r.j || input[j][r.n] != input[j-1][r.n]) {
				range next = f({i, j, r.n+1});
#endif
				int next_score = next.score();
				if (best_score < next_score) {
					best = next;
					best_score = next_score;
				}
				i = j;
				break;
#ifndef SLOW
			}
			next_n_old = next_n;
			next_n = min(next_n, prefijo_comun[j]);
#else
			}
#endif
		}
	}
	return best;
}

using namespace std;

int main () {
#ifndef CLI
	FILE* in_fp = fopen("equipo.in", "r");
	FILE* out_fp = fopen("equipo.out", "w");
#else
	FILE* in_fp = stdin;
	FILE* out_fp = stdout;
#endif
    
	fscanf(in_fp, "%d%d ", &q, &p);

    forn(i, p){
		fread(input_data[i], q, 1, in_fp);
		getc(in_fp);
		input[i] = {input_data[i], q};

#ifdef LOG
		forn(idx, input[i].len)
			cerr << input[i][idx];
		cerr << '\n';
#endif
    }
	sort(input, input+p);

#ifndef SLOW
    forn(i, p-1){
		int comun = 0;
		forn(j, q){
			if(input[i][j] == input[i+1][j])
				comun += 1;
			else break;
		}
		prefijo_comun[i] = comun;
    }
#endif
    
	range best = f({0,p,0});

#ifdef TRACK
	cerr << "f was called " << calls << " times\n";
#endif
    
    fprintf(out_fp, "%d\n", best.score());
    input[best.i][best.n] = 0;
	fputs(input[best.i].s, out_fp);
	fputc('\n', out_fp);
}
