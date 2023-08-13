#include<bits/stdc++.h>
using namespace std;
void suf(string s)
{
    string a="";
    string b="";
    int n=s.length();
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        a+=s[i];
        b=s[n-i-1]+b;
        if(a==b)
        ans=a.length();
    }
    cout<<ans;
}
int main()
{
    string s;
    cin>>s;
    suf(s);
}

/*
#include<bits/stdc++.h>
using namespace std;
int longestPrefixSuffix(string s)
{
	int n = s.length();

	int lps[n];
	lps[0] = 0; // lps[0] is always 0

	// length of the previous
	// longest prefix suffix
	int len = 0;

	// the loop calculates lps[i]
	// for i = 1 to n-1
	int i = (n+1)/2;
	while (i < n)
	{
		if (s[i] == s[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider
			// the example. AAACAAAA
			// and i = 7. The idea is
			// similar to search step.
			if (len != 0)
			{
				len = lps[len-1];

				// Also, note that we do
				// not increment i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}

	int res = lps[n-1];

	// Since we are looking for
	// non overlapping parts.
	return res;
}

// Driver program to test above function
int main()
{
	string s = "bbabbabb";
	cout << longestPrefixSuffix(s);
	return 0;
}

// Corrected by Nilanshu Yadav

*/