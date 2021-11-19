#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map <string, int> mp;
string str[1000020];

bool vozvr(string a, string b) {
	if (b.substr(6, 4) > a.substr(6, 4))
	    return 1;
	else 
	    if (b.substr(6, 4) < a.substr(6, 4))
	    return 0;
	if (b.substr(3, 2) > a.substr(3, 2))
	    return 1;
	else 
	    if (b.substr(3, 2) < a.substr(3, 2))
	    return 0;
	return !(b.substr(0, 2) < a.substr(0, 2));
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> str[i];
		cin >> a;
		mp[str[i]] = max(a, mp[str[i]]);
	}
	
	sort(str + 1, str + N + 1, vozvr);
	for (int i = 2; i <= N; i++) {
		mp[str[i]] = max(mp[str[i - 1]], mp[str[i]]);
	}
	
	int M;
	cin >> M;
	for (int i = 1; i <= M; i++) {
	    int l, ans, r;
	    l = 1;
	    ans = 0;
	    r = N;
	    
		string a;
		cin >> a;
		while (l <= r) {
			int sred;
			sred = (l + r) / 2;
			if (vozvr(str[sred], a)) {
				ans = sred;
				l = sred + 1;
			}
			else {
				r = sred - 1;
			}
		}
		if (ans == 0)
		    cout << 0 << '\n';
		else cout << mp[str[ans]] << '\n';
	}
}