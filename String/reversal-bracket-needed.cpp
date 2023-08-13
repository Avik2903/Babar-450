#include <bits/stdc++.h>
using namespace std;
int countMinReversals(string s)
{
    int n = s.size();
	int c = 0;
    int ans = 0; 
	if (n % 2 != 0)
		return 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '{')
			c++;
		else {
			if (c == 0) {
				ans++;
				c++;
			}
			else
				c--;
		}
	}
	if (c > 0)
		ans += c / 2;
	return ans;
}
int main()
{
	string s = "}{{}}{{{";
    int a = countMinReversals(s);
	if(a>0)
    cout<<a;
    else
    cout<<"No! cant be balanced";
	return 0;
}
