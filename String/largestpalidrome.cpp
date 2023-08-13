#include <bits/stdc++.h>
using namespace std;
int longestsub(string s)
{
    int a = 0, b = 0, c = 0,ans=0,temp;
    int len = s.length();
    if (len < 2)
        return len;
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j >= 0; j--)
        {
            if (s[i] == s[j])
            {
                for (int g = i, h = j; g < h; g++, h--)
                {
                    
                    if (s[g] == s[h])
                        {
                            c++;

                        }
                    else 
                        break;
                }
                if(c>ans)
                {
                    ans=c;
                    temp=j-i;
                    a=i;
                    b=j;
                }
                c=0;
            }
        }
    }
    for(int i=a;i<=b;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    return temp+1;
}
int main()
{
    string s = "abccbaefxyxyyxyx";
    cout << longestsub(s);
    return 0;
}

/*
// A O(n^2) time and O(1) space program to
// find the longest palindromic substring
// easy to understand as compared to previous version.
#include <bits/stdc++.h>
using namespace std;

// A utility function to print
// a substring str[low..high]
// This function prints the
// longest palindrome substring (LPS)
// of str[]. It also returns the
// length of the longest palindrome
int longestPalSubstr(string str)
{
	int n = str.size(); // calculating size of string
	if (n < 2)
		return n; // if string is empty then size will be 0.
				// if n==1 then, answer will be 1(single
				// character will always palindrome)

	int maxLength = 1, start = 0;
	int low, high;
	for (int i = 0; i < n; i++) {
		low = i - 1;
		high = i + 1;
		while (high < n
			&& str[high] == str[i]) // increment 'high'
			high++;

		while (low >= 0
			&& str[low] == str[i]) // decrement 'low'
			low--;

		while (low >= 0 && high < n
			&& str[low] == str[high]) {
			low--;
			high++;
		}

		int length = high - low - 1;
		if (maxLength < length) {
			maxLength = length;
			start = low + 1;
		}
	}

	cout << "Longest palindrome substring is: ";
	cout << str.substr(start, maxLength);
	return maxLength;
}

// Driver program to test above functions
int main()
{
	string str = "forgeeksskeegfor";
	cout << "\nLength is: " << longestPalSubstr(str)
		<< endl;
	return 0;
}

*/