#include <iostream>
#include <string>

using namespace std;

#define forn(i,n) for(int i =0; i <int(n);++i)


int main () {
    
    int t;
    cin >> t;
    
    forn(ti,t){
        string s;
        cin >> s;
        
        s = "0" + s + "0";
        
        string sp;
        forn(i,s.size()-1){
            if(i!=0)sp.push_back(s[i]);
            int diff = int(s[i]) - int(s[i+1]);
            if(diff < 0){
                forn(i,-diff){
                    sp.push_back('(');
                }
            }else if(diff > 0){
                forn(i,diff){
                    sp.push_back(')');
                }
            }
        }

		cout << "Case #" << (ti+1) << ": " << sp << '\n';
    }
}
