#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include <cassert>

#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forsn(i,s,n) for(int i = s; i < int(n); ++i)

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

using std::min;
using std::max;
using std::fill;
using std::vector;
using std::string;

const int logmaxn = 13;
const int maxn = 5000;
int st[logmaxn][maxn];

string_view input[5000];
char input_data[5000][501];

const int inf = 1e9;

int logs[maxn];

void set (int i, int x) {
    st[0][i] = x;
}

void init () {
	forsn(i,1,logmaxn){
		forn(j,maxn){
			st[i][j] = min(st[i-1][j], st[i-1][max(0,j-(1<<(i-1)))]);
		}
	}

	logs[1] = 0;
	forsn(i,2,maxn)
		logs[i] = logs[i/2] + 1;
}

int query (int a, int b) {
	assert(a <= b);

	// Input: [a,b)

	int len = b-a;
	int lg = logs[len];

	// Convert: [a,b]
	--b;

	int lo = st[lg][a + (1 << lg) - 1];
	int hi = st[lg][b];

	return min(lo, hi);
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
    
    int q, p;
	fscanf(in_fp, "%d%d ", &q, &p);
    
    forn(i, p){
		fread(input_data[i], q, 1, in_fp);
		getc(in_fp);
		input[i] = {input_data[i], q};
    }
	sort(input, input+p);
    
    fill(st[0], st[0]+maxn, inf);
    
    forn (i, p-1) {
        int iguales = 0;
        forn(j, q){
            if(input[i][j] == input[i+1][j]) iguales += 1;
			else break;
        }
		// cerr << "A[" << i << "] = " << iguales << "\n";
        set(i, iguales);
    }
    
    init();
    
    int maxa = -inf;
    int maxi = -inf;
    int maxp = -inf;
    forn(i, p-1){
		// cerr << "primero: " << input[i] << '\n';
        forsn(j, i+1, p){
			// rangos [i, j] en los colaboradores, [i, j) en la consulta.

			// cerr << "ultimo: " << input[j] << '\n';

            int col = j-i+1; // cantidad de colaboradores (+1 pq [])
            int preguntas = query(i,j);
            int afinidad = (long long)col*preguntas*preguntas;

			// cerr << "{ colaboradores: " << col << ", comun: " << input[i].substr(0,preguntas) << "(" << preguntas << ") }\n";
			if(maxa < afinidad){
				maxi = i;
				maxa = afinidad;
				maxp = preguntas;
				// cerr << "Mejora!\n";
			}
        }
    }
    
    fprintf(out_fp, "%d\n", maxa);
    input[maxi][maxp] = 0;
	fputs(input[maxi].s, out_fp);
	fputc('\n', out_fp);
}
