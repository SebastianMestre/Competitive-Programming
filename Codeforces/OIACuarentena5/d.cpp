#include <iostream>
#include <string>
using namespace std;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	s.insert(0, 1, '0');
	int mod10 = (s.back() - '0');
	s.pop_back();
	int mod4 = (s.back()*2+mod10)%4;
	int result = mod4?0:4;
	cout << result << '\n';
}

