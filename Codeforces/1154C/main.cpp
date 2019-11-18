#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main () {
    int a;
    int b;
    int c;
 
    cin >> a >> b >> c;
    
    int Sa = a / 3;
    int Sb = b / 2;
    int Sc = c / 2;
 
    int semanas_completas = min(min(Sa, Sb), Sc);
    //if(semanas_completas) semanas_completas -= 1;
 
    int Ra = a - semanas_completas*3;
    int Rb = b - semanas_completas*2;
    int Rc = c - semanas_completas*2;
 
    int Pa[7] = {1,0,0,1,0,0,1};
    int Pb[7] = {0,1,0,0,0,1,0};
    int Pc[7] = {0,0,1,0,1,0,0};
 
    int lar = 0;
 
    for(int i = 0, j = 0; i < 7; ++i){
        while(Ra-Pa[j%7]>=0 && Rb-Pb[j%7]>=0 && Rc-Pc[j%7]>=0){
            Ra -= Pa[j%7];
            Rb -= Pb[j%7];
            Rc -= Pc[j%7];
            j++;
        }
 
        lar = max(lar, j-i);
        Ra += Pa[i%7];
        Rb += Pb[i%7];
        Rc += Pc[i%7];
    }
    
    cout << lar + semanas_completas*7 << '\n';
}
