#include <cstdio>
#include <vector>
#include <tuple>
#include <cstdint>

char world [1000*1001];

int n, m;
std::tuple<int, short, short>* S;
int s_top = 0;

int main () {
	scanf("%d%d", &n, &m);
	getchar_unlocked();
	fread_unlocked(world, 1, n*(m+1)-1, stdin);

	S = (decltype(S))malloc(m*n*sizeof(*S));

	int rooms = 0;
	int vv = 0;
	for(int ii = 0; ii < n; ++ii, vv++){
		for(int jj = 0; jj < m; ++jj, vv++){

			if(world[vv] == '#'){
				continue;
			}

			rooms++;

			world[vv] = '#';
			S[s_top++]={vv, ii, jj};

			while(s_top){
				int vp;

				auto [v, i, j] = S[--s_top];

				vp = v+1;
				if(j < m-1 && (world[vp] != '#')){
					world[vp] = '#';
					S[s_top++]={vp, i, j+1};
				}

				vp = v-1;
				if( j-1 >= 0 && (world[vp] != '#')){
					world[vp] = '#';
					S[s_top++]={vp, i, j-1};
				}

				vp = v-m-1;
				if( i-1 >= 0 && (world[vp] != '#')){
					world[vp] = '#';
					S[s_top++]={vp, i-1, j};
				}

				vp = v+m+1;
				if( i < n-1 && (world[vp] != '#')){
					world[vp] = '#';
					S[s_top++]={vp, i+1, j};
				}
			}
		}
	}

	printf("%d\n", rooms);
}
