/*#include<bits/stdc++.h>
using namespace std;
void findline(string txt,string pat)
{
    int n=txt.length();
    int m=pat.length();
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<m;j++)
            if (txt[i + j] != pat[j])
                break;
        if(j==m)
            cout<<i<<endl;
    }
}
int main()
{
    string txt;
    getline(cin,txt);
    string pat;
    cin>>pat;
    findline(txt,pat);
    return 0;
}*/


#include <bits/stdc++.h>
using namespace std;
#define d 256
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) {

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j]) {
					break;
				}
			}

			// if p == t and pat[0...M-1] = txt[i, i+1,
			// ...i+M-1]

			if (j == M)
				cout << "Pattern found at index " << i
					<< endl;
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			// We might get negative value of t, converting
			// it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

int main()
{
	char txt[] = "this is a test text";
	char pat[] = "test";
	int q = INT_MAX;
	search(pat, txt, q);
	return 0;
}